/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:15:26 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/29 14:15:26 by crebelo-         ###   ########.fr       */
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
	int i = 0;
	while (argv[1][i] != '\0')
		i++;
	i--;
	int	x;
	int	y;

	while (i >= 0)
	{
		y = i;
		while (i >= 0 && (argv[1][i] != ' ' && argv[1][i] != '\t'))
			i--;
		x = i;
		while (++i <= y)
			write(1, &argv[1][i], 1);
		if (x > 0)
			write(1, " ", 1);
		i = x;
		i--;
	}
	write(1, "\n", 1);
}