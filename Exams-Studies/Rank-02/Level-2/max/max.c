/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:33:16 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/08 14:33:16 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	max(int* tab, unsigned int len)
{
	if (!tab)
		return (0);

	int	i = 0;
	int	tmp;
	int	n = tab[0];

	while (i < len)
	{
		tmp = tab[i];
		if (tmp > n)
			n = tmp;
		i++;
	}
	return (n);
}

// int	main()
// {
// 	int a[] = {2,5,40,1,3,4,15,30};

// 	printf("Max number is: %d\n", max(a, 8));
// 	return (0);
// }