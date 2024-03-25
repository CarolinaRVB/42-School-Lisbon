/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:19:10 by crebelo-          #+#    #+#             */
/*   Updated: 2024/03/25 21:19:41 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int				counter = 0;
pthread_mutex_t	mutex;

void	*philo_routine(void *arg)
{
	(void)arg;
	pthread_mutex_lock(&mutex);
	counter++;
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int	create_philosophers(int n)
{
	pthread_t	*th;
	int			i;

	i = 0;
	th = (pthread_t *)ft_calloc(sizeof(pthread_t), n + 1);
	if (!th)
		return (1);
	while (i < n)
	{
		if (pthread_create(&th[i], NULL, &philo_routine, NULL) != 0)
			return (error_msg("Issue in thread create\n", -1));
		printf("Thread %d was created\n", i);
		i++;
	}
	i = 0;
	while (i < n)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (error_msg("issue in thread join\n", -1));
		printf("Thread %d has finished\n", i);
		i++;
	}
	printf("counter: %d\n", counter);
	// free(th);
	return (0);
}

int	check_args_validity(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (error_msg("Error: args: required: 5-6, provided: %d\n", argc));
	while (argc)
	{
		if (!ft_isdigit_str(argv[i]))
			return (error_msg("Error: invalid arg %d\n", ft_atoll(argv[i])));
		argc--;
		i++;
	}
	if (ft_atoll(argv[1]) > 200 || argv[1][0] == '0' || argv[2][0] == '0'
		|| argv[3][0] == '0' || argv[4][0] == '0')
		return (error_msg("Error: invalid arg number\n", -1));
	return (0);
}

void	init_philo_struct(t_philosopher *philo_data, char **argv)
{
	philo_data->n_philos = ft_atoll(argv[1]);
	philo_data->t_death = ft_atoll(argv[2]);
	philo_data->t_eat = ft_atoll(argv[3]);
	philo_data->t_sleep = ft_atoll(argv[4]);
	philo_data->n_meals = ft_atoll(argv[5]);
}

int	main(int argc, char **argv)
{
	t_philosopher	philo_data;

	(void)argv;
	if (check_args_validity(argc, argv) != 0)
		return (1);
	init_philo_struct(&philo_data, argv);
	pthread_mutex_init(&mutex, NULL);
	create_philosophers(philo_data.n_philos);
	pthread_mutex_destroy(&mutex);
	return (0);
}
