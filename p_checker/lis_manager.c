/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:07:07 by alegreci          #+#    #+#             */
/*   Updated: 2023/01/13 10:07:09 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	lis_maker(int *lis, int lis_size, t_list **s_a, t_list **s_b)
{
	int	*arr;
	int	size;
	int	i;
	int	j;

	i = 0;
	j = 0;
	arr = arr_filler(s_a);
	size = ft_lstsize(*s_a);
	while (i < size)
	{
		while (lis[j] != arr[i] && i < size)
		{
			ft_pb(s_a, s_b);
			i++;
		}
		ft_ra(s_a);
		j++;
		i++;
		if (j >= lis_size)
			i = lis_maker_helper(i, size, s_a, s_b);
	}
	free(arr);
}

int	*lis_finder(int *arr, int size)
{
	int		*lis;
	int		i;
	int		j;

	lis = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		lis[i] = 1;
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
			j++;
		}
		i++;
	}
	return (lis);
}

int	lis_size_calculator(int *lis, int size)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	while (i < size)
	{
		if (max < lis[i])
			max = lis[i];
		i++;
	}
	return (max);
}

int	*lis_cleaner(int *lis, int lis_size, int size, int *arr)
{
	int		j;
	int		*tmp;
	int		flag;

	tmp = malloc(sizeof(int) * lis_size);
	while (lis_size > 0)
	{
		j = size -1;
		flag = 1;
		while (j >= 0)
		{
			if (lis[j] == lis_size && flag)
			{
				tmp[lis_size - 1] = arr[j];
				size = j;
				flag = 0;
			}
			j--;
		}
		lis_size--;
	}
	free(lis);
	return (tmp);
}

void	lis_manager(t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		*arr;
	int		*lis;
	int		lis_size;

	size = ft_lstsize(*stack_a);
	arr = arr_filler(stack_a);
	lis = lis_finder(arr, size);
	lis_size = lis_size_calculator(lis, size);
	lis = lis_cleaner(lis, lis_size, size, arr);
	lis_maker(lis, lis_size, stack_a, stack_b);
	free(arr);
	free(lis);
}
