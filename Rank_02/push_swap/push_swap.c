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
	t_list	*stack_a = NULL;
	int	n;

	n = ac;
	args = av;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return(error_exit());
	else if (ac == 2)
	{
		args = ft_split(av[1]);
		ac = ft_strlen(args);
	}	
	if (valid_av(args, ac) != 0 || valid_int(args, ac) != 0 || no_dup(args, ac) != 0)
		return(error_exit());
	
	init_args(stack_a, args, n);
	// t_list *node = stack_a;
	// printf("node %ld\n", node->content);
	// while (node) {
	// 		printf("%ld\n", node->content);
	// 		node = node->next;
	// 	}
	printf("sucess\n");
	return (0);
}