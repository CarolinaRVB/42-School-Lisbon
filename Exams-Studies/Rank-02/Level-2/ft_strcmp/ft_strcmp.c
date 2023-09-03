/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:28:28 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/04 17:28:28 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int res;
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

// int	main()
// {
// 	printf("\nTesting equal strings:\n\n");
// 	char s1[] = "Hello world";
// 	char s2[] = "Hello world";

// 	printf("	Result for ft_strcmp: %d\n", ft_strcmp(s1, s2));
// 	printf("	Result for strcmp: %d\n\n", strcmp(s1, s2));

// 	printf("\nTesting s1 inferior than s2 (negative result):\n\n");
// 	char s3[] = "Hello";
// 	char s4[] = "Hello world";

// 	printf("	Result for ft_strcmp: %d\n", ft_strcmp(s3, s4));
// 	printf("	Result for strcmp: %d\n\n", strcmp(s3, s4));

// 	printf("\nTesting s1 superior than s2 (positive result):\n\n");
// 	char s5[] = "Hello world";
// 	char s6[] = "Hello";

// 	printf("	Result for ft_strcmp: %d\n", ft_strcmp(s5, s6));
// 	printf("	Result for strcmp: %d\n\n", strcmp(s5, s6));

// 	printf("\nTesting for empty string:\n\n");
// 	char s7[] = "";
// 	char s8[] = "";

// 	printf("	Result for ft_strcmp: %d\n", ft_strcmp(s7, s8));
// 	printf("	Result for strcmp: %d\n\n", strcmp(s7, s8));

// 	return (0);
// }