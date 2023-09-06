/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:49:43 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/27 12:49:43 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list  *list_ptr;

	while (begin_list)
	{
		list_ptr = begin_list->next;
		f(begin_list->data);
		begin_list = list_ptr;
	}
}

// void	print_int(void *data)
// {
// 	int *num_ptr = (int *)data;
// 	printf("%d\n", *num_ptr);
// }
// int main() 
// {
	// t_list *list = NULL;
	// t_list *node;
	// int	i = 0;
	// int	ar[] = {2,9,3,1,10,8,5,4,7,6};

	// while (i < 10)
	// {
	// 	node = malloc(sizeof(t_list));
	// 	if (node)
	// 	{
	// 		node->data = &ar[i];
	// 		node->next = list;
	// 		list = node;
	// 		i++;
	// 	}
	// }

// 	ft_list_foreach(list, print_int);
	
// 	while (list)
// 	{
// 		node = list->next;
// 		free(list);
// 		list = node;
// 	}

// 	return (0);
// }