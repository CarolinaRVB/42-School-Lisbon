/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:37:08 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/06/27 14:34:55 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_med(t_stack **stack_a)
{
	int	size;
	int	med;
	int	sum;

	size = stack_size((*stack_a));
	sum = get_stack_sum((*stack_a));
	med = sum / size;
	return (med);
}

void	big_sort(t_stack **stack_a, t_stack **stack_b, t_table *t_info)
{
	int	value;
	int	med;

	t_info = malloc(sizeof(t_table));
	med = 0;
	value = 0;
	while (stack_size((*stack_a)) > 5)
	{
		med = calc_med(stack_a);
		if ((*stack_a)->number < med)
			push_b(stack_b, stack_a);
		else
			rotate_a(stack_a);
	}
	five_random_numbers(stack_a, stack_b);
	while ((*stack_b))
	{
		value = best_solution(stack_a, stack_b, t_info);
		move_top_b(stack_b, get_val_idx(stack_b, value));
		push_a(stack_a, stack_b);
	}
	move_top_a(stack_a, get_val_idx(stack_a, get_min(stack_a)));
	free(t_info);
}
