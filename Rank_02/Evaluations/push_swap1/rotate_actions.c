/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:02:24 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/06/28 13:54:15 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **stack_a)
{
	t_stack	*temp;
	int		tmp;

	temp = (*stack_a);
	write(1, "ra\n", 3);
	while ((*stack_a) != NULL)
	{
		tmp = (*stack_a)->number;
		if ((*stack_a)->next)
		{
			(*stack_a)->number = (*stack_a)->next->number;
			(*stack_a)->next->number = tmp;
		}
		(*stack_a) = (*stack_a)->next;
	}
	(*stack_a) = temp;
}

void	rotate_b(t_stack **stack_b)
{
	t_stack	*temp;
	int		tmp;

	temp = (*stack_b);
	write(1, "rb\n", 3);
	while ((*stack_b) != NULL)
	{
		tmp = (*stack_b)->number;
		if ((*stack_b)->next)
		{
			(*stack_b)->number = (*stack_b)->next->number;
			(*stack_b)->next->number = tmp;
		}
		(*stack_b) = (*stack_b)->next;
	}
	(*stack_b) = temp;
}
