/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 22:40:25 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/09 22:40:25 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	check_doubles(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_doubles2(char *s, char c, int n)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && i < n)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	write_s2_ndups(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		if(check_doubles(s1, s2[i]) == 0)
			if(check_doubles2(s2, s2[i], i) == 0)
				write (1, &s2[i], 1);
		i++;
	}
}

void	write_s1_ndups(char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if(check_doubles2(s1, s1[i], i) == 0)
			write (1, &s1[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}

	write_s1_ndups(argv[1]);
	write_s2_ndups(argv[1], argv[2]);

	write (1, "\n", 1);
	return (0);
}