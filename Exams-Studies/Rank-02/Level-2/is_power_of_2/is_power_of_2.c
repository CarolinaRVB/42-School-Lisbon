/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:31:02 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/08 13:31:02 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	if (n > 0)
	{
		while (n % 2 == 0)
			n /= 2;
	}
	if (n == 1)
		return (n);
	return (0);
}

// int	main()
// {
// 	unsigned int	i;

// 	i = 5;
// 	printf("The result for the number %u is: %d\n", i, is_power_of_2(i));

// 	return (0);
// }