/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:36:47 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/01 18:36:47 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int len = 0;

	while (s2[len] != '\0')
	{
		s1[len] = s2[len];
		len++;
	}	
	s1[len] = '\0';

	return (s1);	
}

// int main() {
// 	char source[] = "Hello, world!";
// 	char destination1[20];
// 	char destination2[20];

// 	strcpy(destination1, source);

// 	printf("Original strcpy function:\n");
// 	printf("Source: %s\n", source);
// 	printf("Destination: %s\n", destination1);
	
// 	printf("\nft_strcpy function:\n");

// 	ft_strcpy(destination2, source);
// 	printf("Source: %s\n", source);
// 	printf("Destination: %s\n", destination2);

// 	return 0;
// }