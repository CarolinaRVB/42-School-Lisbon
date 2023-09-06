/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:35:20 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/08 11:35:20 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<string.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}

	int	i = 0;
	int	j;

	while (argv[1][i] != '\0')
	{
		j = 0;
		while (argv[2][j] != '\0')
		{
			if (argv[1][i] == argv[2][j])
			{
				write(1, &argv[1][i], 1);
				break; 
			}
			j++;
		}
		i++;
		j = 0;
		while (argv[1][j] != '\0' && argv[1][i] != '\0' && j < i)
		{
			if (argv[1][j] == argv[1][i])
			{
				i++;
				break;
			}
			j++;
		}

	}
	write (1, "\n", 1);
	return (0);
}