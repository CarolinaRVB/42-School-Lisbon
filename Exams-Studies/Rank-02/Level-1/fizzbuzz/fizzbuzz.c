/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:53:04 by crebelo-          #+#    #+#             */
/*   Updated: 2023/07/31 19:53:04 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void    write_num(int nb)
{
	if (nb > 9)
		write_num(nb/10);
	nb = nb % 10 + '0';
	write(1, &nb, 1);
}

int main()
{
	int i = 1;

	while (i < 101)
	{
		if ((i % 5 == 0) && (i % 3 == 0))
		{
			write(1, "fizzbuzz", 9);
		}
		else if (i % 3 == 0)
		{
			write(1, "fizz", 5);
		}
		else if (i % 5 == 0)
		{
			write(1, "buzz", 5);
		}
		else
			write_num(i);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
