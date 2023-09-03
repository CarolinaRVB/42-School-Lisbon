/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:38:38 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/07 16:38:38 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include<string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int i;
	int j;

	if (!s1 || !s2)
		return (NULL);

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
				return ((char*)&s1[i]);
			j++;
		}
		j = 0;
		i++;   
	}
	return (NULL);
}

// int main()
// {
// 	const char str1[] = "Hello, World!";
// 	const char str2[] = "Wo";
	
// 	printf("Original function:\n");
// 	char *result1 = strpbrk(str1, str2);
// 	printf("    The first ocurrence of a character from s2 in s1 is: %s\n", result1);

// 	printf("Ft function:\n");
// 	char *result2 = ft_strpbrk(str1, str2);
// 	printf("    The first ocurrence of a character from s2 in s1 is: %s\n", result2);
// 	return 0;
// }