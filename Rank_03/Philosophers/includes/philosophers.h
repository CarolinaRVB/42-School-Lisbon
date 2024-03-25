/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:21:35 by crebelo-          #+#    #+#             */
/*   Updated: 2024/03/25 20:49:49 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct	s_philosopher
{
	pthread_t	th;
	int			n_philos;
	int			t_eat;
	int			t_sleep;
	int			t_death;
	int			n_meals;
	int			id;
	int			l_fork;
	int			r_fork;
	int			t_start;
}	t_philosopher;

/*src/philosophers_utils.c*/
int				error_msg(char *msg, int n);
long long int	ft_atoll(char *str);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isdigit_str(char *arg);
void			ft_usleep(int	time);

#endif
