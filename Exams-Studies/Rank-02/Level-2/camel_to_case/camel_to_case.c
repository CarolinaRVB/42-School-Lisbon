/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:46:55 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/31 15:46:55 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	int	i = 0;
	int	len = 0;
	int	c;

	i = 0;
	while (argv[1][i] != '\0')
	{
		c = argv[1][i];
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			write(1, "_", 1);
			c = argv[1][i] + 32;
		}
		write(1, &c, 1);
		i++;
	}

	write(1, "\n", 1);
	return (0);
}