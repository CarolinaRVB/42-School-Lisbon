/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:39:24 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/29 14:39:24 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	int	i = 0;
	int first;
	int last;
	while (argv[1][i] < 33 || argv[1][i] > 126 && argv[1][i] != '\0')
		i++;
	first = i;
	while (argv[1][i] >= 33 && argv[1][i] <= 126 && argv[1][i] != '\0')
		i++;
	last = i - 1;
	while (argv[1][i] < 33 || argv[1][i] > 126 && argv[1][i] != '\0')
		i++;
	i--;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >= 33 && argv[1][i] <= 126)
		{
			while (argv[1][i] >= 33 && argv[1][i] <= 126 && argv[1][i] != '\0')
			{
				write(1, &argv[1][i], 1);
				i++;
			}
			write(1, " ", 1);
		}
		else
			i++;
	}
	while (first <= last)
	{
		write(1, &argv[1][first], 1);
		first++;
	}
	write(1, "\n", 1);
	return (0);
}