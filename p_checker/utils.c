/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:08:24 by alegreci          #+#    #+#             */
/*   Updated: 2023/01/13 10:08:29 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	mul_rrr(t_list **stack_a, t_list **stack_b, int m)
{
	while (m < 0)
	{
		ft_rrr(stack_a, stack_b);
		m++;
	}
}

int	*arr_filler(t_list **stack)
{
	int		*arr;
	int		i;
	int		size;
	t_list	*tmp;

	size = ft_lstsize(*stack);
	arr = malloc(sizeof(int) * size);
	i = 0;
	tmp = *stack;
	while (i < size)
	{
		arr[i] = tmp->content;
		if (tmp->next)
			tmp = tmp->next;
		i++;
	}
	return (arr);
}

int	mov_cleaner(int *c, int size)
{
	int	i;
	int	res;

	i = 0;
	while (i < size)
	{
		if (c[i] < 0)
			c[i] = -c[i];
		i++;
	}
	i = 0;
	res = 0;
	while (i < size)
	{
		if (c[res] > c[i])
			res = i;
		i++;
	}
	free(c);
	return (res);
}

int	special_place(int *arr, int size)
{
	int	i;
	int	place;

	i = 0;
	place = 0;
	while (i < size)
	{
		if (arr[i] < arr[place])
			place = i;
		i++;
	}
	return (place);
}

int	order_check(t_list **stack)
{
	int	i;
	int	j;
	int	*arr;
	int	size;
	int	res;

	i = 0;
	j = 1;
	arr = arr_filler(stack);
	size = ft_lstsize(*stack);
	res = 1;
	while (j < size)
	{
		if (arr[i] > arr[j])
			res = 0;
		i++;
		j++;
	}
	free(arr);
	return (res);
}
