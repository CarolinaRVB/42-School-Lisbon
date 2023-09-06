/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:34:27 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/14 12:34:27 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	str_minimise(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}

	int	i = 1;
	int	j;

	while (argc-- != 1)
	{
		str_minimise(argv[i]);
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] >= 'a' && argv[i][j] <= 'z') && ((argv[i][j - 1] == ' ' || argv[i][j - 1] == '\t') || j == 0))
				argv[i][j] = argv[i][j] - 32;
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}