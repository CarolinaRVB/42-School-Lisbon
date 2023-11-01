/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:45:06 by crebelo-          #+#    #+#             */
/*   Updated: 2023/11/01 13:45:06 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv(char **ar)
{
	int	i;

	i = 0;
	while (ar[i] != NULL)
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}

int	check_arguments(char **args, int ac, int n)
{
	if (valid_av(args, ac, n) != 0 || valid_int(args, ac, n) != 0
		|| no_dup(args, ac, n) != 0)
		return (error_exit());
	if (n == 1)
		return (1);
	return (0);
}

void	start_sort(t_list **stack_a, t_list **stack_b, int ac, int n)
{
	if (is_sorted(stack_a) != 0)
		sort_list(stack_a, stack_b, ac, n);
	free_list(stack_a);
}
