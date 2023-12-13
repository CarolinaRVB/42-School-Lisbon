/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 08:50:45 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/06/27 15:17:58 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_front(t_stack **head, int data)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	new_node->number = data;
	new_node->next = *head;
	new_node->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}

void	insert_end(t_stack **head, int data)
{
	t_stack	*new_node;
	t_stack	*temp;

	temp = *head;
	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return ;
	new_node->number = data;
	new_node->next = NULL;
	if ((*head) == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
}

void	delete_node(t_stack **head, int key)
{
	t_stack	*temp;

	temp = *head;
	*head = temp->next;
	if (*head != NULL && temp->number == key)
		(*head)->prev = NULL;
	free(temp);
}

void	free_list(t_stack *head)
{
	t_stack	*current;
	t_stack	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
