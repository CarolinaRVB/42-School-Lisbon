/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_big_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:44:18 by crebelo-          #+#    #+#             */
/*   Updated: 2023/10/17 19:44:18 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_top_rr(t_list **a, t_list **b, t_list *min, t_list *target)
{
	int	m_dis;
	int	d_target;

	m_dis = min->index;
	d_target = target->index;
	if (m_dis > d_target)
		top_rr_b(a, b, m_dis, d_target);
	else
		top_rr_a(a, b, m_dis, d_target);
}

void	top_rr_b(t_list **a, t_list **b, int m_dis, int t_dis)
{
	m_dis = m_dis - t_dis;
	while (t_dis > 0)
	{
		rr(a, b);
		t_dis--;
	}
	while (m_dis > 0)
	{
		rb(b);
		write(1, "rb\n", 3);
		m_dis--;
	}
}

void	top_rr_a(t_list **a, t_list **b, int m_dis, int t_dis)
{
	t_dis = t_dis - m_dis;
	while (m_dis > 0)
	{
		rr(a, b);
		m_dis--;
	}
	while (t_dis > 0)
	{
		ra(a);
		write(1, "ra\n", 3);
		t_dis--;
	}
}

t_list	*find_next_big(t_list *a, t_list *max)
{
	t_list	*target;
	t_list	*tmpa;

	tmpa = a;
	target = NULL;
	while (tmpa && tmpa->next != NULL)
	{
		if (target == NULL)
			target = tmpa;
		if (tmpa && tmpa->next != NULL && (tmpa->next->content < max->content)
			&& (tmpa->next->content > target->content))
			target = tmpa->next;
		tmpa = tmpa->next;
	}
	return (target);
}

t_list		*find_median(t_list **a)
{
	int	j;
	t_list	*max;
	t_list	*next_big;

	max = get_max(*a);
	j = ft_lstlast(*a)->index / 2;
	while (j > 0)
	{
		next_big = find_next_big(*a, max);
		max = next_big;
		j--;
	}
	return (next_big);
}


// t_list	*get_median(t_list **a, t_list *max)
// {
// 	t_list	*min;
// 	int		mean;

// 	min = get_min_val(*a);
// 	mean = ft_lstlast(*a)->index / 2;



// }