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

void	big_sort(t_list **a, t_list **b)
{
	// int cost_b;

	// cost_b = b->index;
	// if (b->index > len/2)
	// 	cost_b = cost_value(b, b->index);
	while (ft_lstlast(*a)->index > 4)
	{
		pb(a, b);
		reset_index(a);
		write(1, "pb\n", 3);
	}
}