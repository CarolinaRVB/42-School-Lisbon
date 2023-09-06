/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:22:09 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/11 12:22:09 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	n = n % 10 + '0';
	write(1, &n, 1);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		write (1, "0", 1);
		return (0);
	}

	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}