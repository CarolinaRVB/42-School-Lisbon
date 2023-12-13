/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation_actions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:20:03 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/06/28 13:54:19 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*temp;
	int		saver;
	int		last;

	temp = (*stack_a);
	write(1, "rra\n", 4);
	while ((*stack_a)->next)
		(*stack_a) = (*stack_a)->next;
	last = (*stack_a)->number;
	(*stack_a) = temp;
	while ((*stack_a))
	{
		saver = (*stack_a)->number;
		(*stack_a)->number = last;
		last = saver;
		(*stack_a) = (*stack_a)->next;
	}
	(*stack_a) = temp;
}

void	reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*temp;
	int		saver;
	int		last;

	temp = (*stack_b);
	write(1, "rrb\n", 4);
	while ((*stack_b)->next)
		(*stack_b) = (*stack_b)->next;
	last = (*stack_b)->number;
	(*stack_b) = temp;
	while ((*stack_b))
	{
		saver = (*stack_b)->number;
		(*stack_b)->number = last;
		last = saver;
		(*stack_b) = (*stack_b)->next;
	}
	(*stack_b) = temp;
}
