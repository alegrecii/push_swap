/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_applier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:07:22 by alegreci          #+#    #+#             */
/*   Updated: 2023/01/13 10:07:24 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	mov_maker(t_list **stack, int m, int s)
{
	if (s)
	{
		if (m > 0)
			mul_ra(stack, m);
		else
			mul_rra(stack, m);
	}
	else
	{
		if (m > 0)
			mul_rb(stack, m);
		else
			mul_rrb(stack, m);
	}
}

void	mov_applier(int a, int b, t_list **stack_a, t_list **stack_b)
{
	if ((a > 0 && b < 0) || (a == 0 || b == 0) || (a < 0 && b > 0))
	{
		mov_maker(stack_a, a, 1);
		mov_maker(stack_b, b, 0);
	}
	if (a > 0 && b > 0 && a >= b)
	{
		mul_rr(stack_a, stack_b, b);
		mov_maker(stack_a, a - b, 1);
	}
	if (a > 0 && b > 0 && a < b)
	{
		mul_rr(stack_a, stack_b, a);
		mov_maker(stack_b, b - a, 0);
	}
	if (a < 0 && b < 0 && a <= b)
	{
		mul_rrr(stack_a, stack_b, b);
		mov_maker(stack_a, a - b, 1);
	}
	if (a < 0 && b < 0 && a > b)
	{
		mul_rrr(stack_a, stack_b, a);
		mov_maker(stack_b, b - a, 0);
	}
}
