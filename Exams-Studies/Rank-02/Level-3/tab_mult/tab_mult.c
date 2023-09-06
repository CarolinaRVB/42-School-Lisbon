/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:54:47 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/14 17:54:47 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

int	ft_atoi(char *s)
{
	int i = 0;
	int	res = 0;
	
	while (s[i] != '\0' && (s[i] >= '0' && s[i] <= '9'))
		res = res * 10 + (s[i++] - '0');
	return (res);
}

int	count(int n)
{
	int	count = 0;
	int	nb = n;

	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}

	int	n = ft_atoi(argv[1]);
	char	*ar = "123456789";
	int	a = 1;
	int	i = 0;
	int len;
	int	j;
	int	mult;

	while (a < 10)
	{
		j = 0;
		write(1, &ar[i], 1);
		write (1, " x ", 3);
		while (argv[1][j] != '\0')
		{
			write(1, &argv[1][j], 1);
			j++;
		}
		write (1, " = ", 3);
		mult = a * n;
		len = count(mult);
		char res[len];
		res[len] = '\0';
		while (mult > 0)
		{
			res[--len] = (mult % 10) + '0';
			mult = mult / 10;
		}
		j = 0;
		while (res[j] != '\0')
		{
			write(1, &res[j], 1);
			j++;
		}	
		write(1, "\n", 1);
		a++;
		i++;
	}
	return (0);
}