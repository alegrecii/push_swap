/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:07:47 by alegreci          #+#    #+#             */
/*   Updated: 2023/01/13 10:07:49 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_b, tmp);
	write(1, "pb\n", 3);
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_a, tmp);
	write(1, "pa\n", 3);
}
