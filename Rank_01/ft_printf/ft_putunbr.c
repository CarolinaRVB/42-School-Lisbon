/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:20:43 by crebelo-          #+#    #+#             */
/*   Updated: 2023/05/04 09:20:43 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(unsigned int n, size_t *len)
{
	if (n > 9)
		ft_putnbr_fd((n / 10), 1, len);
	n = n % 10 + '0';
	write(1, &n, 1);
	(*len)++;
}
