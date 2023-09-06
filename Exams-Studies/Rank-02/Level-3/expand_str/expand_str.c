/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:27:06 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/10 21:27:06 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char *argv[])
{
	if (argc != 2 || argv[1] == NULL)
	{
		write(1, "\n", 1);
		return (0);
	}

	int	i = 0;
	int j = 0;
	int	x;

	while(argv[1][j] != '\0')
		j++;
	j--;
	while (argv[1][j] == ' ' || argv[1][j] == '\t' || argv[1][j] == '\n')
		j--;
	while (argv[1][i] == ' ' || argv[1][i] == '\t' || argv[1][i] == '\n')
		i++;
	while (argv[1][i] != '\0' && i <= j)
	{
		if (argv[1][i] == ' ' || argv[1][i] == '\t' || argv[1][i] == '\n')
		{
			x = 3;
			while (x-- > 0)
				write(1, " ", 1);
		}			
		while ((argv[1][i] == ' ' || argv[1][i] == '\t' || argv[1][i] == '\n') && argv[1][i + 1] != '\0')
			i++;
		write(1, &argv[1][i], 1);
		i++;
	}
	write (1, "\n", 1);
	return (0);
}