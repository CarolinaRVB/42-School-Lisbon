/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:01:26 by crebelo-          #+#    #+#             */
/*   Updated: 2023/10/04 15:01:26 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_value(t_list *lst, int index)
{
	int len;
	int cost;

	len = ft_lstlast(lst)->index + 1;
	cost = len - index;
	return (cost);
}