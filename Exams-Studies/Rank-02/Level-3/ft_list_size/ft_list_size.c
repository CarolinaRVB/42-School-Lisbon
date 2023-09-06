/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:42:14 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/10 21:42:14 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_list_size.h"

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list != 0)
	{
		count++;
		begin_list = begin_list->next;
	}
	return(count);
}

int main() {
	// Create a sample linked list
	t_list *node1 = (t_list *)malloc(sizeof(t_list));
	t_list *node2 = (t_list *)malloc(sizeof(t_list));
	t_list *node3 = (t_list *)malloc(sizeof(t_list));
	node1->data = 10;
	node1->next = node2;
	node2->data = 20;
	node2->next = node3;
	node3->data = 30;
	node3->next = NULL;

	int size = ft_list_size(node1);

	printf("Size of the linked list: %d\n", size);

	free(node1);
	free(node2);
	free(node3);

	return 0;
}