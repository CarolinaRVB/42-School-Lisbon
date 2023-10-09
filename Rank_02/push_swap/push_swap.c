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
#include <string.h>

int	ft_strlen(char **str)
{
	int	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int main(int ac, char *av[])
{
	char	**args;
	t_list	*stack_a;
	t_list	*stack_b;
	int	n;

	n = ac;
	args = av;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return(error_exit());
	else if (ac == 2)
	{
		args = ft_split(av[1]);
		ac = ft_strlen(args);
	}	
	if (valid_av(args, ac) != 0 || valid_int(args, ac) != 0 || no_dup(args, ac, n) != 0)
		return(error_exit());
	
	init_args(&stack_a, args, n);
	if (is_sorted(&stack_a) != 0)
		sort_list(&stack_a, &stack_b, ac);

	while(stack_a)
	{
		printf("%d: ", stack_a->index);
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	printf("\n\n");
	while(stack_b)
	{
		printf("%d: ", stack_b->index);
		printf("%d\n", stack_b->content);
		stack_b = stack_b->next;
	}
	// free_list(&stack_a);
	// printf("sucess\n");
	return (0);
}
// printf("error\n");

	// while(stack_a)
	// {
	// 	printf("%ld\n", stack_a->content);
	// 	stack_a = stack_a->next;
	// }
	