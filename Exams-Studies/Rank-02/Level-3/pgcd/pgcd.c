/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:33:30 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/11 12:33:30 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("\n");
		return (0);
	}

	int	n1 = atoi(argv[1]);
	int	n2 = atoi(argv[2]);
	
	if (n1 > 0 && n2 > 0)
	{
		while (n1 != n2)
		{
			if (n1 > n2)
				n1 -= n2;
			else
				n2 -= n1;
		}
		printf("%d\n", n1);
	}
	return (0);
}