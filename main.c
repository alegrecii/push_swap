/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:07:14 by alegreci          #+#    #+#             */
/*   Updated: 2023/01/13 10:07:15 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*fill_a(int argc, char **argv)
{
	t_list	**a;
	t_list	*tmp;
	int		i;
	long	n;

	i = 1;
	a = malloc(sizeof(*a));
	*a = NULL;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (n > 2147483647 || n < -2147483648)
		{
			write(1, "Error\n", 6);
			return (NULL);
		}
		tmp = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(a, tmp);
		i++;
	}
	tmp = *a;
	free(a);
	return (tmp);
}

void	special_cases(int argc, t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;

	tmp = stack_a;
	if (argc == 3)
		order2(&stack_a);
	else if (argc == 4)
		order3(&stack_a);
	else if (argc == 5)
		order4(&stack_a, &stack_b);
	else if (argc == 6)
		order5(&stack_a, &stack_b, tmp);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argv_check(argv, argc))
		return (0);
	stack_a = fill_a(argc, argv);
	stack_b = NULL;
	if (argc < 3 || check_double(&stack_a) || order_check(&stack_a))
	{
		if (argc != 1)
			list_free(&stack_a);
		return (0);
	}
	else if (argc < 7)
	{
		special_cases(argc, stack_a, stack_b);
		list_free(&stack_a);
	}
	else
	{
		lis_manager(&stack_a, &stack_b);
		while (ft_lstsize(stack_b) > 0)
			mov_counter(&stack_a, &stack_b);
		finisher(&stack_a);
	}
}
