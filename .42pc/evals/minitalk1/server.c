/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguilla <ayguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:05:13 by mric              #+#    #+#             */
/*   Updated: 2023/06/13 14:34:30 by ayguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void	ft_putnbr(int n)
{
	char	temp;

	if (n / 10 > 0)
		ft_putnbr(n / 10);
	temp = n % 10 + '0';
	write (1, &temp, 1);
}

void	ft_reception(int num)
{
	static int	i = 0;
	static char	c = 0xFF;

	if (num == SIGUSR2)
		c ^= 0x80 >> i;
	else if (num == SIGUSR1)
		c |= 0x80 >> i;
	i++;
	if (i == 8)
	{
		write (1, &c, 1);
		i = 0;
		c = 0xFF;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = &ft_reception;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "Server PID ==> ", 15);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
	}
	return (0);
}
