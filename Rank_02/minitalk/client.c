/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:29:21 by crebelo-          #+#    #+#             */
/*   Updated: 2023/12/13 12:29:21 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int PID, char *msg)
{
	int				bits;
	unsigned char	c;

	while (*msg)
	{
		bits = 8;
		c = *msg;
		while (bits--)
		{
			if (c >> bits & 1)
				kill(PID, SIGUSR1);
			else
				kill(PID, SIGUSR2);
			usleep(100);
		}
		msg++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (ft_error_exit("Error\nInvalid number of arguments.\n"));
	if (ft_isdigit(ft_atoi(argv[1])) != 0)
		return (ft_error_exit("Error\nInvalid PID number.\n"));
	if (!argv[2][0])
		return (ft_error_exit("Error\nEmpty message.\n"));
	send_message(ft_atoi(argv[1]), argv[2]);
	send_message(ft_atoi(argv[1]), "\n");
	return (EXIT_SUCCESS);
}
