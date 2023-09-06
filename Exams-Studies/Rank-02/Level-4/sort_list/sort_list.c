/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:50:13 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/18 10:50:13 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include <stdio.h>
#include "sort_list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*tmp = lst;
	int		n;

	while(lst->next != NULL)
	{
		if(((*cmp)(lst->data, lst->next->data)) == 0)
		{
			n = lst->data;
			lst->data = lst->next->data;
			lst->next->data = n;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

// int compare(int a, int b) {
// 	if (b < a)
// 		return (0);
// 	else
// 		return (1);
// }
// int main() {
// 	t_list *list = NULL;
// 	t_list *node;
// 	int	i = 0;
// 	int	ar[] = {2,9,3,1,10,8,5,4,7,6};

// 	while (i < 10)
// 	{
// 		node = malloc(sizeof(t_list));
// 		if (node)
// 		{
// 			node->data = ar[i];
// 			node->next = list;
// 			list = node;
// 			i++;
// 		}
// 	}

// 	printf("Original list:\n");
// 	node = list;
// 	while (node) {
// 		printf("%d ", node->data);
// 		node = node->next;
// 	}
// 	printf("\n");

// 	list = sort_list(list, compare);

// 	printf("Sorted list:\n");
// 	node = list;
// 	while (node) {
// 		printf("%d ", node->data);
// 		node = node->next;
// 	}
// 	printf("\n");

// 	while (list) {
// 		node = list->next;
// 		free(list);
// 		list = node;
// 	}

// 	return (0);
// }