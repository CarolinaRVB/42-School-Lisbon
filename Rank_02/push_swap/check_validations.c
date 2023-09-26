/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:24:10 by crebelo-          #+#    #+#             */
/*   Updated: 2023/09/26 11:07:21 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_exit(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	valid_av(char **av, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (is_digit(av[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	valid_int(char **av, int size)
{
	int			i;
	long int	n;

	i = 0;
	while (i < size)
	{
		n = ft_atoll(av[i]);
		if (n > 2147483647)
			return (1);
		if (n < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int	no_dup(char **av, int size)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (i < size && j < size)
	{	
		i = 1;
		while (i < j)
		{
			if (av[i] == av[j])
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
