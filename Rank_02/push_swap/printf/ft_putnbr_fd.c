/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:26:34 by crebelo-          #+#    #+#             */
/*   Updated: 2023/05/05 10:19:02 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd, size_t *len)
{
	if (n == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		(*len) += 2;
		n = 147483648;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		(*len)++;
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd, len);
	}
	n = n % 10 + '0';
	write(fd, &n, 1);
	(*len)++;
}
