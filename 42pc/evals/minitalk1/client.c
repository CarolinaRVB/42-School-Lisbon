/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguilla <ayguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:05:20 by mric              #+#    #+#             */
/*   Updated: 2023/06/13 14:34:25 by ayguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *nptr)
{
	int	s;
	int	res;

	s = 1;
	res = 0;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t'
		|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			s = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = (res * 10) + (*nptr - '0');
		nptr++;
	}
	return (res * s);
}

void	ft_send_char(int pid, char c)
{
	int	b;
	int	comp;

	b = 7;
	while (c && b >= 0)
	{
		comp = c >> b;
		if (comp & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		b--;
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int					pid;

	if (argc != 3)
		write (1, "Missing arg => ./client [SERV_PID] [MESSAGE]", 44);
	else
	{
		pid = ft_atoi(argv[1]);
		while (argv[2] && *argv[2])
			ft_send_char(pid, *argv[2]++);
		ft_send_char(pid, '\n');
		write(1, "congrats! The message has been sent to the server", 51);
	}
	return (0);
}
