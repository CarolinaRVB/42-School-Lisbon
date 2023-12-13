/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:25:54 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/06/28 13:54:08 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack_a)
{
	t_stack	*temp;
	int		tmp;

	write(1, "sa\n", 3);
	temp = (*stack_a);
	tmp = (*stack_a)->number;
	(*stack_a)->number = (*stack_a)->next->number;
	(*stack_a)->next->number = tmp;
	(*stack_a) = temp;
}

void	swap_b(t_stack **stack_b)
{
	t_stack	*temp;
	int		tmp;

	write(1, "sb\n", 3);
	temp = (*stack_b);
	tmp = (*stack_b)->number;
	(*stack_b)->number = (*stack_b)->next->number;
	(*stack_b)->next->number = tmp;
	(*stack_b) = temp;
}
