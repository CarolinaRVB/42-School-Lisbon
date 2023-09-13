/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:23:21 by crebelo-          #+#    #+#             */
/*   Updated: 2023/09/13 18:23:21 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int i = 0;
	unsigned char re = 0;

	while (i < 8)
	{
		re = (re << 1 ) | (octet >> i ) & 1;
		i++;
	}
	return re;
}

void	print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char bit;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

char	swap_bit(unsigned char octet)
{
	return ((octet >> 4 )|(octet << 4));
}

int	main()
{
	unsigned char octet = 2;
	unsigned char bit = reverse_bits(octet);
	print_bits(bit);
	write(1, "\n", 1);
	print_bits(octet);
	write(1, "\n", 1);
	print_bits(swap_bit(octet));
}