/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:15:13 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/29 17:15:13 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	int num = atoi(argv[1]);
	if (num == 1)
	{
		printf("1\n");
		return (0);
	}
	
	int	i = 2;
	int	j = 2;
	int	prime;
	while (i <= num)
	{
		if (num % i == 0)
		{
			if (i != num)
				printf("%d*", i);
			else
				printf("%d", i);
			num /= i;
			i = 1;
		}
		i++;
	}
	printf("\n");
	return (0);
}