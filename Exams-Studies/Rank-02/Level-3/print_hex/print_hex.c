/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:59:17 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/13 11:59:17 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_atoi(char *nb)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (nb[i] != '\0')
		res = res * 10 + (nb[i++] - '0');
	return (res);
}

void	print_hex(int n)
{	
	char *base = "0123456789abcdef";

	if (n >= 16)
		print_hex(n / 16);
	write(1, &base[n % 16], 1);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write (1, "\n", 1);
		return (0);
	}

	int	n = ft_atoi(argv[1]);	
	print_hex(n);
	
	write (1, "\n", 1);
	return (0);
}