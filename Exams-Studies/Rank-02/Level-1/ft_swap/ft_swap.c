/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:31:19 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/02 15:31:19 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

// int	main()
// {
// 	int	a = 2;
// 	int	b = 3;

// 	printf("Value of a before swap: %d\n", a);
// 	printf("Value of b before swap: %d\n", b);

// 	ft_swap(&a, &b);
// 	printf("Value of a after swap: %d\n", a);
// 	printf("Value of b after swap: %d\n", b);
// }