/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:25:39 by crebelo-          #+#    #+#             */
/*   Updated: 2023/09/27 17:25:39 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_sort(t_list **a, t_list **b)
{
	t_list	*min;
	int		min_index;

	min = is_min(a);
	min_index = min->index;
	if (min_index == 1)
		sa(a);
	else if (min_index == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_index == 3)
	{
		rra(a);
		rra(a);
	}
	else if (min_index == 4)
		rra(a);
	pb(a, b);
	write(1, "pb\n", 3);
	reset_lst(a);
}

void	four_sort(t_list **a, t_list **b)
{
	t_list	*min;
	int		min_index;

	min = is_min(a);
	min_index = min->index;
	if (min_index == 1)
		sa(a);
	else if (min_index == 2)
	{
		rra(a);
		rra(a);
	}
	else if (min_index == 3)
		rra(a);
	pb(a, b);
	write(1, "pb\n", 3);
	reset_lst(a);
}

void	three_sort(t_list **a, t_list **b)
{
	t_list	*min;
	int		min_index;

	min = is_min(a);
	min_index = min->index;
	if (min_index == 1)
		sa(a);
	else if (min_index == 2)
		rra(a);
	pb(a, b);
	write(1, "pb\n", 3);
	reset_lst(a);
}

void	small_sort(t_list **a, t_list **b, int size)
{
	if (ft_lstlast(*a)->index == 4)
		five_sort(a, b);
	if (ft_lstlast(*a)->index == 3)
		four_sort(a, b);
	if (ft_lstlast(*a)->index == 2)
		three_sort(a, b);
	if ((*a)->content > (*a)->next->content)
		sa(a);
	while (size - 4 >= 0)
	{
		pa(a, b);
		size--;
	}
}

void	sort_list(t_list **a, t_list **b, int size)
{
	if (size <= 6)
		small_sort(a, b, size);
	else
	{
		while (ft_lstlast(*a)->index > 4)
		{
			pb(a, b);
			reset_lst(a);
			write(1, "pb\n", 3);
		}
		small_sort(a, b, 6);
		reset_lst(b);
		big_sort(a, b);
	}	
	sort_final(a);
}
