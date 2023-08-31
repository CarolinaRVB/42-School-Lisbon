/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:47:47 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/03 18:47:47 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	char	c;
	int		i = 0;

	while (argv[1][i] != '\0')
	{	
		if (argv[1][i]>= 'a' && argv[1][i] <= 'z')
		{
			if (argv[1][i] > 'm')
				c = (97 + ((argv[1][i] + 13) - 123));
			else
				c = argv[1][i] + 13;
			write(1, &c, 1);
		}
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			if (argv[1][i] > 'M')
				c = (65 + ((argv[1][i] + 13) - 91));
			else
				c = argv[1][i] + 13;
			write(1, &c, 1);
		}
		else
			write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}