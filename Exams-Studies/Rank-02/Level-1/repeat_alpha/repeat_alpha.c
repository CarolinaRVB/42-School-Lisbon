/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:06:23 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/02 18:06:23 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 2 || *argv[1] == '\0')
	{
		write(1, "\n", 1);
		return (0);
	}

	int		i = 0;
	int		j = 0;
	char	alphabet_big[26] = "abcdefghijklmnopqrstuvwxyz";
	char	alphabet_small[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char	c;

	while (argv[1][i] != '\0')
	{
		if (argv[1][i] < 'a' || argv[1][i] >'z' || argv[1][i] < 'A' || argv[1][i] > 'Z')
			write(1, &argv[1][i], 1);
		while (alphabet_big[j] != '\0' && alphabet_small[j] != '\0')
		{
			if (argv[1][i] == alphabet_big[j] || argv[1][i] == alphabet_small[j])
			{
				while (j-- >= 0)
					write(1, &argv[1][i], 1);
				break ;
			}
			else
				j++;
		}
		j = 0;
		i++;
	}
	write(1, "\n", 1);
	return (0);
}