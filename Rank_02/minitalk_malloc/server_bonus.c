/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:40:46 by crebelo-          #+#    #+#             */
/*   Updated: 2023/12/11 10:40:46 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*msg = NULL;

void	add_chr_to_msg(char chr, unsigned long nchrs)
{
	char	*new_msg;

	new_msg = (char *)malloc(sizeof(char) * (nchrs + 2));
	if (new_msg)
	{
		if (msg)
		{
			ft_memmove(new_msg, msg, nchrs);
			free(msg);
		}
		new_msg[nchrs] = chr;
		new_msg[nchrs + 1] = '\0';
		msg = new_msg;
	}
}

void	siginfo_handler(int num, siginfo_t *info, void *context)
{
	static int	c = 0;
	static unsigned long	i = 0;
	static unsigned long	chrs = -1;

	(void)context;
	if (num == SIGUSR1)
		c = (c << 1) | 1;
	else if (num == SIGUSR2)
		c = (c << 1);
	i++;
	if (i == 8)
	{
		chrs += 1;
		if (c == 10)
		{
			kill(info->si_pid, SIGUSR1);
			ft_printf("%s\n", msg);
			free(msg);
			chrs = -1;
			msg = NULL;
		}
		else
			add_chr_to_msg(c, chrs);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = siginfo_handler;
	sigact.sa_flags = SA_SIGINFO;
	sigemptyset(&sigact.sa_mask);
	if (sigaction(SIGUSR1, &sigact, NULL) == -1
		|| sigaction(SIGUSR2, &sigact, NULL) == -1)
		return (ft_error_exit("Error\nIssue with sigaction.\n"));
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
