/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:03:19 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/07 16:03:19 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;	
	while (src[i] != '\0')
		i++;
	dest = (char *)malloc((i + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}	
	dest[i] = '\0';
	return (dest);
}

// int	main()
// {
// 	char *src = "Hello world";
// 	char *dest;
// 	char	*dest2;
	
// 	dest = ft_strdup(src);
// 	dest2 = strdup(src);
// 	printf("Original function: %s\n", dest2);
// 	printf("My function: %s\n", dest);

// 	return (0);
// }