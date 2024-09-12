/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:08:09 by alegreci          #+#    #+#             */
/*   Updated: 2023/01/13 10:08:12 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order2(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (tmp->content > tmp->next->content)
		ft_sa(stack_a);
}

void	order3(t_list **stack_a)
{
	int		a;
	int		b;
	int		c;
	t_list	*tmp;

	tmp = *stack_a;
	a = tmp->content;
	b = tmp->next->content;
	c = tmp->next->next->content;
	if (b < a && b < c && c > a)
		ft_sa(stack_a);
	else if (a > b && a > c && c > b)
		ft_ra(stack_a);
	else if (a > c && b > c && a < b)
		ft_rra(stack_a);
	else if (a > b && b > c)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (b > c && c > a)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
}

void	order4(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		a;
	int		b;
	int		c;
	int		d;

	tmp = *stack_a;
	a = tmp->content;
	b = tmp->next->content;
	c = tmp->next->next->content;
	d = tmp->next->next->next->content;
	if (b < a && b < c && b < d)
		ft_sa(stack_a);
	else if (c < a && c < b && c < d)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (d < a && d < b && d < c)
		ft_rra(stack_a);
	ft_pb(stack_a, stack_b);
	order3(stack_a);
	ft_pa(stack_a, stack_b);
}

void	order5help(t_list **stack_a, t_list **stack_b)
{
	ft_pb(stack_a, stack_b);
	order4(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	order5(t_list **stack_a, t_list **stack_b, t_list *tmp)
{
	int		a;
	int		b;
	int		c;
	int		d;
	int		e;

	a = tmp->content;
	b = tmp->next->content;
	c = tmp->next->next->content;
	d = tmp->next->next->next->content;
	e = tmp->next->next->next->next->content;
	if (b < a && b < c && b < d && b < e)
		ft_sa(stack_a);
	else if (c < a && c < b && c < d && c < e)
		mul_ra(stack_a, 2);
	else if (d < a && d < b && d < c && d < e)
		mul_rra(stack_a, -2);
	else if (e < a && e < b && e < c && e < d)
		ft_rra(stack_a);
	order5help(stack_a, stack_b);
}
