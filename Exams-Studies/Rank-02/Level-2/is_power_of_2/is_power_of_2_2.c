/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:09:50 by crebelo-          #+#    #+#             */
/*   Updated: 2023/09/08 11:09:50 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
	int	nb = 0;
	if (n == 0)
		return (0);
	while(n > 1)
	{
		if (n % 2 != 0)
			return (0);
		n = n / 2;
	}
	return (1);
}

// int	main()
// {
// 	printf("%d", is_power_of_2(0));
// }