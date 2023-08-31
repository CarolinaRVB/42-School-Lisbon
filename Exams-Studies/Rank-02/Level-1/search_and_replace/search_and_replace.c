/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:22:44 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/03 19:22:44 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	if (argc != 4 || ft_strlen(argv[2]) != 1 || ft_strlen(argv[3]) != 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	int	i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == *argv[2])
			write(1, &*argv[3], 1);
		else
			write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}