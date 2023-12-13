/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:12:52 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/06/28 14:26:49 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	move_top_a(t_stack **head, int distance)
{
	int	tmp;

	if (distance == 0)
		return ;
	if (distance <= (stack_size((*head)) / 2))
	{
		while (distance > 0)
		{
			rotate_a(head);
			distance--;
		}
	}
	else
	{
		tmp = stack_size((*head)) - distance;
		while (tmp > 0)
		{
			reverse_rotate_a(head);
			tmp--;
		}
	}
}

void	move_top_b(t_stack **head, int distance)
{
	int	tmp;

	if (distance == 0)
		return ;
	if (distance <= (stack_size((*head)) / 2))
	{
		while (distance > 0)
		{
			rotate_b(head);
			distance--;
		}
	}
	else
	{
		tmp = stack_size((*head)) - distance;
		while (tmp > 0)
		{
			reverse_rotate_b(head);
			tmp--;
		}
	}
}
