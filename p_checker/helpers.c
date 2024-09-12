/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:06:58 by alegreci          #+#    #+#             */
/*   Updated: 2023/01/13 10:07:00 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	mul_rr(t_list **stack_a, t_list **stack_b, int m)
{
	while (m > 0)
	{
		ft_rr(stack_a, stack_b);
		m--;
	}
}

void	mul_ra(t_list **stack, int m)
{
	while (m > 0)
	{
		ft_ra(stack);
		m--;
	}
}

void	mul_rra(t_list **stack, int m)
{
	while (m < 0)
	{
		ft_rra(stack);
		m++;
	}
}

void	mul_rb(t_list **stack, int m)
{
	while (m > 0)
	{
		ft_rb(stack);
		m--;
	}
}

void	mul_rrb(t_list **stack, int m)
{
	while (m < 0)
	{
		ft_rrb(stack);
		m++;
	}
}
