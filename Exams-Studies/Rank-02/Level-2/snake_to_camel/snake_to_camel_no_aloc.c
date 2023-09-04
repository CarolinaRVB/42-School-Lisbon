/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:47:49 by crebelo-          #+#    #+#             */
/*   Updated: 2023/07/18 17:16:19 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return  (0);
	}
	
	int	i;
	char	a;
	
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == '_')
		{
			a = argv[1][++i] - 32;
			write(1, &a, 1);
		}
		else
			write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);	
}
