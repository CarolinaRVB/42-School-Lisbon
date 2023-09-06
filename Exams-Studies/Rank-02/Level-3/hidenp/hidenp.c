/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:40:00 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/10 22:40:00 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}

	int	i = 0;
	int	j = 0;
	int	len = 0;

	while (argv[1][len] != '\0')
		len++;
	while (argv[1][i] != '\0')
	{
		while (argv[2][j] != '\0')
		{
			if (argv[1][i] == argv[2][j])
			{
				i++;
				j++;
				break;
			}
			else
				j++;
		}
		if (argv[2][j] == '\0' && i < len)
		{
			write(1, "0\n", 2);
			return (0);
		}	
	}
	write(1, "1\n", 2);
	return (0);
}