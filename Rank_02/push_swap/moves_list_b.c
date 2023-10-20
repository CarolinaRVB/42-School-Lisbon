/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_list_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:36:21 by crebelo-          #+#    #+#             */
/*   Updated: 2023/10/16 17:36:21 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **lst)
{
	t_list	*lst_ptr;
	t_list	*last;
	t_list	*tmp;

	tmp = (*lst)->next;
	lst_ptr = *lst;
	last = ft_lstlast(lst_ptr);
	last->next = lst_ptr;
	lst_ptr->next = NULL;
	*lst = tmp;
}

void	rrb(t_list **lst)
{
	t_list	*last;
	t_list	*before_last;

	before_last = *lst;
	last = ft_lstlast(*lst);
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last->next = *lst;
	before_last->next = NULL;
	*lst = last;
}

void	pb(t_list **a, t_list **b)
{
	t_list	*lst_ptr;

	lst_ptr = *a;
	*a = (*a)->next;
	ft_lstadd_front(b, lst_ptr);
	reset_lst(b);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
