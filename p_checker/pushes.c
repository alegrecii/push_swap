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

#include "checker.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_b, tmp);
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_a, tmp);
}
