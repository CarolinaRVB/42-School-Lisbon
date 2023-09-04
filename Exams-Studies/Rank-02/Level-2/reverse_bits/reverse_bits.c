/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:33:48 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/10 16:33:48 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int	i = 0;
	unsigned char	res = 0;

	while (i < 8)
	{
		res = (res << 1) | (octet >> i) & 1;
		i++;
	}
	return (res);
}

// void print_binary(unsigned char value)
// {
// 	for (int i = 7; i >= 0; i--)
// 	{
// 		printf("%u", (value >> i) & 1);
// 	}
// 	printf("\n");
// }

// int main()
// {
// 	unsigned char c = 1;

// 	print_binary(reverse_bits(c));

// 	return(0);
// }