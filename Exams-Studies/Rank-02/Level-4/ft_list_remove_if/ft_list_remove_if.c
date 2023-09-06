/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:59:59 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/28 11:59:59 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*list_ptr;
	t_list	*tmp;

	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		list_ptr = *begin_list;
		*begin_list = (*begin_list)->next;
		free(list_ptr);
	}
	list_ptr = *begin_list;
	while (list_ptr && list_ptr->next)
	{
		if (cmp(list_ptr->next->data, data_ref) == 0)
		{
			tmp = list_ptr->next;
			list_ptr->next = tmp->next;
			free(tmp);
		}
		list_ptr = list_ptr->next;
	}
}

// int compare(int *a, int *b) {
// 	if (*b == *a)
// 		return (0);
// 	else
// 		return (1);
// }

// int main() 
// {
// 	t_list *list = NULL;
// 	t_list *node;
// 	int	i = 0;
// 	int	ar[] = {2,9,3,1,10,8,5,4,7,6};

// 	while (i < 10)
// 	{
// 		node = malloc(sizeof(t_list));
// 		if (node)
// 		{
// 			node->data = &ar[i];
// 			node->next = list;
// 			list = node;
// 			i++;
// 		}
// 	}

// 	printf("Original List:\n");
// 	node = list;
// 	while (node) {
// 		printf("%p\n", node->data);
// 		node = node->next;
// 	}

// 	int	remove = 3;
// 	ft_list_remove_if(&list, &remove, compare);
	
// 	printf("List after removal:\n");
// 	node = list;
// 	while (node) {
// 		printf("%p\n", node->data);
// 		node = node->next;
// 	}

// 	while (list)
//     {
//         node = list->next;
//         free(list);
//         list = node;
//     }

// 	return (0);
// }