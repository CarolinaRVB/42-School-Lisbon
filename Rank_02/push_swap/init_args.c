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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	free_list(t_list **stack)
{
	t_list	*node;
	t_list	*tmp;

	node = *stack;
	while(node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(stack);
}

void	init_args(t_list **stack, char **av, int ac)
{
	t_list  *node;
	int		i;

	i = 1;
	if (ac == 2)
	{
		ac = ft_strlen(av);
		i = 0;
	}
	while (i < ac)
	{
		node = malloc(sizeof(t_list));
		if (node)
		{
			node->content = ft_atoll(av[i]);
			node->next = NULL;
			ft_lstadd_back(stack, node);
		}
		else
		{
			free_list(stack);
			error_exit();
		}
		i++;
	}
}