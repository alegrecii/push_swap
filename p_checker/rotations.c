/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:10:05 by alegreci          #+#    #+#             */
/*   Updated: 2023/01/13 13:10:08 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotator(t_list **stack)
{
	t_list	*last;
	t_list	*first;

	last = ft_lstlast(*stack);
	first = *stack;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}

void	ft_ra(t_list **stack)
{
	rotator(stack);
}

void	ft_rb(t_list **stack)
{
	rotator(stack);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	rotator(stack_a);
	rotator(stack_b);
}
