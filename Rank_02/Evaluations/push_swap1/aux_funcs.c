/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:28:02 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/06/29 10:41:28 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_limits(long int result)
{
	if (result > INT_MAX || result < INT_MIN)
		error_msg();
}

int	ft_atoi_max(const char *str)
{
	int			i;
	int			sign;
	long int	result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result += str[i] - '0';
		i++;
	}
	check_limits(result * sign);
	return (result * sign);
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	valid_num_str(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '\0')
		return (0);
	if (s[0] == '-' && ft_is_digit(s[1]))
		i++;
	while (s[i])
	{
		if (!ft_is_digit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
