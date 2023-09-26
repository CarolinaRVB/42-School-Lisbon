/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:26:42 by crebelo-          #+#    #+#             */
/*   Updated: 2023/09/26 12:26:42 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_args(t_list *stack, char **av, int ac)
{
	t_list  *node;
	int		i;

	i = 1;
	if (ac == 2)
		ac = ft_strlen(av);
	
	while (i < ac)
	{
		node = malloc(sizeof(t_list) * ac);
		if (node)
		{
			node->content = ft_atoll(av[i]);
			node->next = stack;
			stack = node;
			i++;
		}
		else
			error_exit();
	}
}