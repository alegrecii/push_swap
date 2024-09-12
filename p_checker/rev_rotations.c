/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:08:02 by alegreci          #+#    #+#             */
/*   Updated: 2023/01/13 10:08:04 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rev_rotator(t_list **stack)
{
	t_list	*last;
	t_list	*plast;

	last = *stack;
	plast = *stack;
	while (last->next != NULL)
	{
		plast = last;
		last = last->next;
	}
	last->next = *stack;
	*stack = last;
	plast->next = NULL;
}

void	ft_rra(t_list **stack)
{
	rev_rotator(stack);
}

void	ft_rrb(t_list **stack)
{
	rev_rotator(stack);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotator(stack_a);
	rev_rotator(stack_b);
}
