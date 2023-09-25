/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:06:03 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/06/30 11:19:52 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack);
	while (tmp && tmp->next)
	{
		if (tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	def_cases(t_stack *stack_a, t_stack *stack_b, t_table *t_info, int size)
{
	if (check_sorted(&stack_a) == 0)
	{
		if (size == 2)
			two_numbers_case(&stack_a);
		else if (size == 3)
			three_random_numbers(&stack_a);
		else if (size == 4)
			four_random_numbers(&stack_a, &stack_b);
		else if (size == 5)
			five_random_numbers(&stack_a, &stack_b);
		else if (size > 5)
			big_sort(&stack_a, &stack_b, t_info);
	}
	free_list(stack_a);
	free_list(stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_table	*t_info;
	int		size;

	t_info = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	validator(av, &stack_a);
	if (check_sorted(&stack_a))
	{
		free_list(stack_a);
		free_list(stack_b);
		exit(0);
	}
	size = stack_size(stack_a);
	def_cases(stack_a, stack_b, t_info, size);
	return (0);
}
