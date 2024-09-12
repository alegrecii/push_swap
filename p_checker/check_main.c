/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <alegreci>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:55:39 by alegreci          #+#    #+#             */
/*   Updated: 2023/03/06 16:09:16 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line.h"

int	str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] && s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		else
			i++;
	}
	return (1);
}

void	do_move(char *move, t_list **stack_a, t_list **stack_b)
{
	if (str_cmp(move, "ra\n") == 1)
		ft_ra(stack_a);
	else if (str_cmp(move, "rb\n") == 1)
		ft_rb(stack_b);
	else if (str_cmp(move, "rra\n") == 1)
		ft_rra(stack_a);
	else if (str_cmp(move, "rrb\n") == 1)
		ft_rrb(stack_b);
	else if (str_cmp(move, "rrr\n") == 1)
		ft_rrr(stack_a, stack_b);
	else if (str_cmp(move, "rr\n") == 1)
		ft_rr(stack_a, stack_b);
	else if (str_cmp(move, "sa\n") == 1)
		ft_sa(stack_a);
	else if (str_cmp(move, "sb\n") == 1)
		ft_sb(stack_b);
	else if (str_cmp(move, "ss\n") == 1)
		ft_ss(stack_a, stack_b);
	else if (str_cmp(move, "pa\n") == 1)
		ft_pa(stack_a, stack_b);
	else if (str_cmp(move, "pb\n") == 1)
		ft_pb(stack_a, stack_b);
	else if (str_cmp(move, "Error\n") == 1)
		write(1, "input error\n", 12);
}

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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*move;

	if (argc == 1)
		return (0);
	stack_a = fill_a(argc, argv);
	stack_b = NULL;
	move = malloc(sizeof(char) * 2);
	move[0] = '0';
	move[1] = '\0';
	while (move != NULL)
	{
		free (move);
		move = get_next_line(0);
		if (move == NULL)
			break ;
		do_move(move, &stack_a, &stack_b);
	}
	if (order_check(&stack_a) && stack_b == NULL)
		write(1, "ok\n", 3);
	else
		write(1, "ko\n", 3);
}
