/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:06:35 by alegreci          #+#    #+#             */
/*   Updated: 2023/01/13 10:06:41 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_double(t_list **stack)
{
	int		*arr;
	int		n;
	int		size;
	int		i;

	arr = arr_filler(stack);
	size = ft_lstsize(*stack);
	n = 0;
	while (n < size)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == arr[n] && i != n)
			{
				write(1, "Error\n", 6);
				free(arr);
				return (1);
			}
			i++;
		}
		n++;
	}
	free(arr);
	return (0);
}

int	check_num(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9')
				&& argv[i][j] != '-' && argv[i][j] != '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	argv_check(char **argv, int argc)
{
	if (check_num(argv, argc))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
