/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:08:17 by alegreci          #+#    #+#             */
/*   Updated: 2023/01/13 10:08:19 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swapper(t_list **stack)
{
	t_list	*start;
	t_list	*tmp;

	start = *stack;
	tmp = start->next;
	*stack = tmp;
	start->next = tmp->next;
	tmp->next = start;
}

void	ft_sa(t_list **stack_a)
{
	swapper(stack_a);
}

void	ft_sb(t_list **stack_b)
{
	swapper(stack_b);
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	swapper(stack_a);
	swapper(stack_b);
}
