/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finisher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:06:48 by alegreci          #+#    #+#             */
/*   Updated: 2023/01/13 10:06:53 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	lis_maker_helper(int i, int size, t_list **s_a, t_list **s_b)
{
	while (i < size)
	{
		ft_pb(s_a, s_b);
		i++;
	}
	return (i);
}

void	list_free(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*bye;

	tmp = *stack_a;
	while (tmp->next)
	{
		bye = tmp;
		tmp = tmp->next;
		free(bye);
	}
	free(tmp);
}

void	finisher(t_list **stack_a)
{
	int		size;
	int		*arr;
	int		place;

	arr = arr_filler(stack_a);
	size = ft_lstsize(*stack_a);
	place = special_place(arr, size);
	if (place <= size / 2)
		mul_ra(stack_a, place);
	else
		mul_rra(stack_a, place - size);
	free(arr);
	list_free(stack_a);
}
