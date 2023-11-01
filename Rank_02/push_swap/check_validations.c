/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:24:10 by crebelo-          #+#    #+#             */
/*   Updated: 2023/11/01 12:29:39 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char **str)
{
	int	i;

	i = 1;
	while (str[i] != NULL)
		i++;
	return (i);
}

int	error_exit(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	valid_av(char **av, int size, int n)
{
	int	i;

	i = 1;
	if (n == 2)
		i = 0;
	while (i < size)
	{
		if (is_digit(av[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	valid_int(char **av, int size, int n)
{
	int			i;
	long int	nb;

	i = 1;
	if (n == 2)
		i = 0;
	while (i < size)
	{
		nb = ft_atoll(av[i]);
		if (nb > 2147483647)
			return (1);
		if (nb < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int	no_dup(char **av, int size, int n)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	if (n == 2)
	{
		i = 0;
		j = 1;	
	}
	while (i < size && j < size)
	{
		i = 1;
		if (n == 2)
			i = 0;
		while (i < j)
		{
			if (ft_atoll(av[i]) == ft_atoll(av[j]))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
