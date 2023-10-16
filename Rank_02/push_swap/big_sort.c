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
		if (tmp->target == NULL)
		{
			tmp->cost = INT_MAX;
			tmp->target = *a;
		}	
		else
			tmp->cost = tmp->index;
		cost_target = tmp->target->index;
		if (tmp->index > (ft_lstlast(*b)->index + 1) / 2
			&& tmp->cost != INT_MAX)
			tmp->cost = cost_value(tmp, tmp->index);
		if (tmp->target->index > (ft_lstlast(*a)->index + 1) / 2)
			cost_target = cost_value(*a, tmp->target->index);
		tmp->cost = tmp->cost + cost_target;
		tmp = tmp->next;
	}
}

void	move_top_b(t_list **b, t_list *min)
{
	int	last;

	last = ft_lstlast(*b)->index + 1;
	if (min->index > last / 2)
	{
		while (last - min->index > 0)
		{
			rrb(b);
			min->index = min->index + 1;
		}
	}
	else
	{
		while (min->index > 0)
		{
			rb(b);
			min->index = min->index - 1;
		}
	}
}

void	move_top_a(t_list **a, t_list *target)
{
	int	last;

	last = ft_lstlast(*a)->index + 1;
	if (target->index > last / 2)
	{
		while (last - target->index > 0)
		{
			rra(a);
			target->index = target->index + 1;
		}
	}
	else
	{
		while (target->index > 0)
		{
			ra(a);
			target->index = target->index - 1;
		}
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
		if (min->cost == INT_MAX)
		{
			min = get_max(*b);
			min->target = get_max(*a)->next;
		}
		move_top_a(a, min->target);
		move_top_b(b, min);
		pa(a, b);
		reset_lst(b);
		reset_lst(a);
	}
}
