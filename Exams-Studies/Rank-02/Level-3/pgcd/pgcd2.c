/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:41:50 by crebelo-          #+#    #+#             */
/*   Updated: 2023/09/08 08:41:50 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc != 3 || atoi(argv[1]) < 0 || atoi(argv[2]) < 0)
	{
		printf("\n");
		return (0);
	}

	int	n1 = atoi(argv[1]);
	int	n2 = atoi(argv[2]);
	int	cd = 0;
	int i = 1;

	while (i <= n1 && i <= n2)
	{
		if (n1%i == 0 && n2%i == 0)
			cd = i;
		i++;
	}
	printf("%d\n", cd);
	return (0);
}