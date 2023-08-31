/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:19:20 by crebelo-          #+#    #+#             */
/*   Updated: 2023/07/19 14:19:20 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

int	ft_atoi(const char *str)
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
// int	main()
// {
// 	char	str[] = "  +456  76" ;
// 	printf("%d", ft_atoi(str));
// 	return (0);
// }