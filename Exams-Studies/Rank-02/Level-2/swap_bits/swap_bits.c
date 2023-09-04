/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:39:51 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/10 16:39:51 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

// void	print_bits(unsigned char octet)
// {
// 	int i;
// 	unsigned char bit;

// 	i = 8;
// 	while (i--)
// 	{
// 		bit = (octet >> i & 1) + '0';
// 		write (1, &bit, 1);
// 	}
// }

// int main()
// {
// 	unsigned char c = 22;

// 	print_bits(swap_bits(c));
// 	return(0);
// }