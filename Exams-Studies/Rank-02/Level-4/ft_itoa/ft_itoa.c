/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:18:29 by crebelo-          #+#    #+#             */
/*   Updated: 2023/07/27 18:18:29 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>

char	*ft_itoa(int nbr)
{
    char    *str;
	int		len;
	int		n;
    int		i;

	i = 0;
	len = 0;
	n = nbr;
	if (nbr == -2147483648)
		return("-2147483648\0");
	if (nbr < 0)
		len++;
	while (n)
	{
		n = n/10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[--len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}

// int	main()
// {
// 	int	nb;
// 	int	i = 0;
// 	char	*str;

// 	nb = -214;
// 	str = ft_itoa(nb);
// 	while (str[i]){
// 		write(1, &str[i], 1);
// 		i++;}
// 	return (0);
// }