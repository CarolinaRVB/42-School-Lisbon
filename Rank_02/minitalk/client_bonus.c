/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 09:21:57 by crebelo-          #+#    #+#             */
/*   Updated: 2023/12/03 09:21:57 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message successfully received\n");
	else
		ft_printf("Error: Message was not received properly.\n");
}

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
			usleep(500);
		}
		msg++;
	}
}


int	main(int argc, char **argv)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	if (argc != 3)
		return (ft_error_exit("Error\nInvalid number of arguments.\n"));
	if (ft_isdigit(ft_atoi(argv[1])) != 0)
		return (ft_error_exit("Error\nInvalid PID number.\n"));
	if (!argv[2][0])
		return (ft_error_exit("Error\nEmpty message.\n"));
	sigaction(SIGUSR1, &sa, NULL);
	send_message(ft_atoi(argv[1]), argv[2]);
	send_message(ft_atoi(argv[1]), "\n");
	return (EXIT_SUCCESS);
}
