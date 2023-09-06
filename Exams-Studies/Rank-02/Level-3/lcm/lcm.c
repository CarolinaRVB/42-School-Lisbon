/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:47:58 by crebelo-          #+#    #+#             */
/*   Updated: 2023/09/05 15:47:58 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
unsigned int    lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);
	int	n = 1;

	while (1)
	{
		if(n % a == 0 && n % b == 0)
			return (n);
		n++;
	}
}

// int	main()
// {
// 	unsigned int	a = 8;
// 	unsigned int	b = 5;

// 	printf("%d", lcm(a, b));
// }