/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:07:33 by alegreci          #+#    #+#             */
/*   Updated: 2023/01/13 10:07:35 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mov_chooser(t_mov mov, int size, int *c, int i)
{
	while (i < size)
	{
		if (mov.a[i] == 0 || mov.b[i] == 0)
			c[i] = mov.a[i] + mov.b[i];
		if (mov.a[i] > 0 && mov.b[i] > 0)
		{
			if (mov.a[i] > mov.b[i])
				c[i] = mov.a[i];
			else
				c[i] = mov.b[i];
		}
		if (mov.a[i] > 0 && mov.b[i] < 0)
			c[i] = mov.a[i] - mov.b[i];
		if (mov.a[i] < 0 && mov.b[i] > 0)
			c[i] = mov.b[i] - mov.a[i];
		if (mov.a[i] < 0 && mov.b[i] < 0)
		{
			if (mov.a[i] < mov.b[i])
				c[i] = mov.a[i];
			else
				c[i] = mov.b[i];
		}
		i++;
	}
	return (mov_cleaner(c, size));
}

void	b_filler(int *mov, t_list **stack_b)
{
	int		size;
	int		i;
	int		j;

	size = ft_lstsize(*stack_b);
	i = 0;
	while (i <= size / 2)
	{
		mov[i] = i;
		i++;
	}
	i = size -1;
	j = -1;
	while (i > size / 2)
	{
		mov[i] = j;
		i--;
		j--;
	}
}

int	pos_finder(int n, int *a, int size)
{
	int	pos;
	int	i;

	i = 0;
	while (i < size && a[i] < n)
		i++;
	if (i < size)
		pos = i;
	else
		pos = 0;
	while (i < size)
	{
		if (a[pos] > a[i] && a[i] > n)
			pos = i;
		i++;
	}
	if (pos == 0 && n > a[pos])
		pos = special_place(a, size);
	if (pos <= size / 2)
		return (pos);
	else
		return (pos - size);
}

void	a_filler(int *mov, t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		*a;
	int		*b;
	int		i;

	i = 0;
	a = arr_filler(stack_a);
	b = arr_filler(stack_b);
	size = ft_lstsize(*stack_b);
	while (i < size)
	{
		mov[i] = pos_finder(b[i], a, ft_lstsize(*stack_a));
		i++;
	}
	free(a);
	free(b);
}

void	mov_counter(t_list **stack_a, t_list **stack_b)
{
	t_mov	mov;
	int		chosen;
	int		i;
	int		*c;

	i = 0;
	c = malloc(sizeof(int) * ft_lstsize(*stack_b));
	mov.a = malloc(sizeof(int) * ft_lstsize(*stack_b));
	mov.b = malloc(sizeof(int) * ft_lstsize(*stack_b));
	b_filler(mov.b, stack_b);
	a_filler(mov.a, stack_a, stack_b);
	chosen = mov_chooser(mov, ft_lstsize(*stack_b), c, i);
	mov_applier(mov.a[chosen], mov.b[chosen], stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	free(mov.a);
	free(mov.b);
}
