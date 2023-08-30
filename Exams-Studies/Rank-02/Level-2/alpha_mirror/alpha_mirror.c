/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:45:42 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/04 15:45:42 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	int		i = 0;
	char	c;

	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
		{
			c = 122 - argv[1][i] + 'a';
			write(1, &c, 1);
		}
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			c = 90 - argv[1][i] + 'A';
			write(1, &c, 1);
		}
		else
			write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
