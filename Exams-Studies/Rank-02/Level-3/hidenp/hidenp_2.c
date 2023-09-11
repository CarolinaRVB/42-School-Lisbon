/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:46:16 by crebelo-          #+#    #+#             */
/*   Updated: 2023/09/11 12:46:16 by crebelo-         ###   ########.fr       */
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

	int	j = 0;
	int	i = 0;
	while (argv[2][j] != '\0')
	{
		while (argv[1][i] != '\0' && argv[2][j] != '\0')
		{	
			if(argv[1][i] == argv[2][j])
				i++;
			break ;
		}
		j++;
	}
	if (argv[1][i] == '\0')
		write(1, "1\n", 2);
	else
		write(1, "0\n", 2);
	return (0);
}