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

//	LOGIC: 
//	1: check if no arguments are given or empty argument
//	2: If argument is given in one string, if it has more 
// than 1 element, do split
// else, n (equal to ac) is given the value 1
// 	3: check validity of arguments given
// 	4: if passed, initiate stack
//	5: sort the stack
//  6: if the value of n is 2, meaning the split occured 
// and string has more than one number, 
// free the args variable.

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		n;

	n = ac;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2 || (ac == 2 && count_words(av[1], ' ') == 0))
		return (0);
	if (ac == 2)
	{
		ac = count_words(av[1], ' ');
		if (ac != 1)
			av = ft_split(av[1], ' ');
		else
			n = 1;
	}
	if (check_arguments(av, ac, n) != 0)
		return (1);
	init_args(&stack_a, av, n);
	start_sort(&stack_a, &stack_b, ac, n);
	if (n == 2 && ac > 1)
		free_argv(av);
	return (0);
}
