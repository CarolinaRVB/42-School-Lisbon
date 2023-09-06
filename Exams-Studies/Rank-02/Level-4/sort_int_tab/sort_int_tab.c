/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:18:45 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/16 18:18:45 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	int	i = 0;
	int j;
	int	tmp;

	while (i <= size - 1)
	{
		j = i + 1;
		while (j <= size - 1)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

// int	main()
// {
// 	int	a[]= {12,5,10,9,7,6,8,5,1};
// 	int	i = 0;

// 	int	length = sizeof(a)/sizeof(a[0]);

// 	printf("Unsorted tab: ");
// 	while(i < length)
// 	{
// 		printf("%d", a[i]);
// 		if (i != length - 1)
// 			printf(", ");
// 		i++;
// 	}
// 	printf("\n");

// 	sort_int_tab(a, length);

// 	i = 0;
// 	printf("  Sorted tab: ");
// 	while(i < length)
// 	{
// 		printf("%d", a[i]);
// 		if (i != length - 1)
// 			printf(", ");
// 		i++;
// 	}
// 	printf("\n");
// }