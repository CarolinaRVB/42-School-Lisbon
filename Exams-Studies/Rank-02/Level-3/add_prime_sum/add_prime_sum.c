/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ad_prime_sum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:00:21 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/10 17:00:21 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_atoi(char *str)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while(str[i] != '\0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

void	ft_putnbr(int n)
{
	char nb;

	if (n >= 10)
		ft_putnbr(n / 10);
	nb = n % 10 + '0';
	write(1, &nb, 1);
}

int	is_prime(int n)
{
	int	i = 2;

	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc != 2 && ft_atoi(argv[1]) < 0)
	{
		write (1, "\n", 1);
		return (0);
	}

	int	n = ft_atoi(argv[1]);
	int	res = 0;
	while (n > 1)
	{
		if (is_prime(n))
			res = res + n;
		n--;
	}

	ft_putnbr(res);
	write (1, "\n", 1);
	return (0);
}