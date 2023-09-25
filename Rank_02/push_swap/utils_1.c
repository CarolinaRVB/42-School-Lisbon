/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:09:01 by crebelo-          #+#    #+#             */
/*   Updated: 2023/09/24 15:09:01 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <unistd.h>

int is_digit(char *av)
{
	int i = 0;
	while(av[i] != '\0')
	{
		if (av[i] >= '0' && av[i] <= '9')
		{
			i++;
		}	
		else
			return (1);
	}
	return (0);
}

int	check_doubles(char **av, char c, int n)
{
	int	i;

	i = 0;
	while (*av[i] != '\0' && i < n - 1)
	{
		if (*av[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	i = 0;
	int	res = 0;
	int	sign = 1;

	while (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}