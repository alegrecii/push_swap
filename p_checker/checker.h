/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:56:23 by alegreci          #+#    #+#             */
/*   Updated: 2023/01/16 10:56:26 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

void	finisher(t_list **stack_a);
void	swapper(t_list **stack);
void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **stack);
void	ft_rb(t_list **stack);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack);
void	ft_rrb(t_list **stack);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
void	order2(t_list **stack_a);
void	order3(t_list **stack_a);
void	order4(t_list **stack_a, t_list **stack_b);
void	order5(t_list **stack_a, t_list **stack_b, t_list *tmp);
void	lis_manager(t_list **stack_a, t_list **stack_b);
int		*arr_filler(t_list **stack);
int		mov_cleaner(int *c, int size);
void	mov_applier(int a, int b, t_list **stack_a, t_list **stack_b);
void	mul_ra(t_list **stack, int m);
int		lis_maker_helper(int i, int size, t_list **s_a, t_list **s_b);
void	mul_rra(t_list **stack, int m);
void	mul_rb(t_list **stack, int m);
void	mul_rrb(t_list **stack, int m);
void	mul_rr(t_list **stack_a, t_list **stack_b, int m);
void	mul_rrr(t_list **stack_a, t_list **stack_b, int m);
int		special_place(int *arr, int size);
int		argv_check(char **argv, int argc);
int		check_double(t_list **stack);
void	list_free(t_list **stack_a);
int		order_check(t_list **stack);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
long	ft_atoi(const char *str);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
#endif
