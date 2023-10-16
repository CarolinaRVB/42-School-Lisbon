/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:24:10 by crebelo-          #+#    #+#             */
/*   Updated: 2023/10/16 17:26:00 by crebelo-         ###   ########.fr       */
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

int	check_dup(char *n1, char *n2)
{
	int	i;

	i = 0;
	while (n1[i] != '\0' && n2[i] != '\0')
	{
		if (n1[i] == n2[i])
			i++;
		else
			return (0);
	}
	if (n1[i] == '\0' && n2[i] == '\0')
		return (1);
	else
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
			if (check_dup(av[i], av[j]) != 0)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
