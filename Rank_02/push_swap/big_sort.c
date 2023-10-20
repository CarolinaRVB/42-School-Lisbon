/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:19:00 by crebelo-          #+#    #+#             */
/*   Updated: 2023/10/03 18:19:00 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_target_cost(t_list **a, t_list **b)
{
	int		cost_target;
	t_list	*tmp; 

	tmp = *b;
	while (tmp != NULL)
	{
		tmp->target = find_target(*a, tmp);
		tmp->cost = tmp->index;
		cost_target = tmp->target->index;
		if (tmp->index > (ft_lstlast(*b)->index + 1) / 2)
			tmp->cost = ft_lstlast(*b)->index + 1 - tmp->index;
		if (tmp->target->index > (ft_lstlast(*a)->index + 1) / 2)
			cost_target = ft_lstlast(*a)->index + 1 - tmp->target->index;
		tmp->cost = tmp->cost + cost_target;
		tmp = tmp->next;
	}
}

void	move_top(t_list **a, t_list **b, t_list *min, t_list *target)
{
	int	last_a; 
	int	last_b;

	last_a = ft_lstlast(*a)->index + 1;
	last_b = ft_lstlast(*b)->index + 1;
	if (target->index > last_a / 2 && min->index > last_b / 2)
		move_top_rrr(a, b, min, target);
	else if (target->index < last_a / 2 && min->index < last_b / 2)
		move_top_rr(a, b, min, target);
	else
	{
		move_top_a(a, target);
		move_top_b(b, min);
	}
}

void	sort_final(t_list **a)
{
	t_list	*min;

	min = get_min_val(*a);
	move_top_a(a, min);
	reset_lst(a);
}

void	big_sort(t_list **a, t_list **b)
{
	t_list	*min;

	min = *b;
	while (*b)
	{
		get_target_cost(a, b);
		min = get_min(*b);
		move_top(a, b, min, min->target);
		pa(a, b);
		reset_lst(b);
		reset_lst(a);
	}
}
