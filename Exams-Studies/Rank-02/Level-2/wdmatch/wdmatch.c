/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:15:21 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/10 15:15:21 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	check_match(char *s1, char *s2)
{
	int	i = 0;
	int	j = 0;
	int	len = 0;

	while (s1[len] != '\0')
		len++;
	
	while (s1[i] != '\0')
	{
		while (s2[j] != '\0')
		{
			if (s1[i] != s2[j])
				j++;
			else
				break;
		}
		if (s2[j] == '\0' && i < len)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	
	int	i = 0;

	if (check_match(argv[1], argv[2]) == 0)
	{
		write(1, "\n", 1);
		return (0);
	}

	while (argv[1][i] != '\0')
	{
		write (1, &argv[1][i], 1);
		i++;
	}

	write (1, "\n", 1);
	return (0);
} 