/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:32:22 by crebelo-          #+#    #+#             */
/*   Updated: 2023/09/27 19:32:22 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **lst)
{
	t_list	*tmp;
	int	size;

	size = list_size(lst);
	if (size < 2)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	tmp->next = *lst;
	*lst = tmp;
	write(1, "sa\n", 3);
}

void	ra(t_list **lst)
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
	write(1, "ra\n", 3);
}

void rra(t_list **lst)
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
	write(1, "rra\n", 4);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*lst_ptr;

	lst_ptr = *a;
	*a = (*a)->next;
	ft_lstadd_front(b, lst_ptr);
	reset_index(b);
}

void	pa(t_list **a, t_list **b)
{
	pb(b, a);
	write(1, "pa\n", 3);
}

// void	sa(t_list **lst)
// {
// 	int	tmp;
// 	int	size;

// 	size = list_size(lst);
// 	if (size < 2)
// 		return ;
// 	tmp = (*lst)->content;
// 	(*lst)->content = (*lst)->next->content;
// 	(*lst)->next->content = tmp;
// 	write(1, "sa\n", 3);
// }

// void	ra(t_list **lst)
// {
// 	t_list	*lst_ptr;
// 	int 	tmp;

// 	tmp = (*lst)->content;
// 	lst_ptr = *lst;
// 	while ((*lst)->next != NULL)
// 	{
// 		(*lst)->content = (*lst)->next->content;
// 		*lst = (*lst)->next;
// 		if ((*lst)->next == NULL)
// 			(*lst)->content = tmp;
// 	}
// 	*lst = lst_ptr;
// }

