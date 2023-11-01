/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:44:39 by crebelo-          #+#    #+#             */
/*   Updated: 2023/09/23 10:44:39 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	char	**args;
	t_list	*stack_a;
	t_list	*stack_b;
	int		n;

	n = ac;
	args = av;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2 || (ac == 2 && count_words(av[1]) == 0))
		return (0);
	if (ac == 2)
	{		
		n = count_words(av[1]);
		if (n != 1)
			args = ft_split(av[1]);
		ac = ft_strlen(args);
	}
	if (check_arguments(args, ac, n) != 0)
		return (1);
	init_args(&stack_a, args, n);
	start_sort(&stack_a, &stack_b, ac, n);
	if (n == 2)
		free_argv(args);
	return (0);
}
