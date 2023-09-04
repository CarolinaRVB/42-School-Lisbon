/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:24:33 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/07 17:24:33 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int	i;
	int	j;
	int tmp;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
				break;
			j++;
		}
		if (accept[j] == '\0')
			break;
		i++;
	}
	return (i);
}

// int main() 
// {
// 	const char str1[] = "Hello, World!";
// 	const char str2[] = "ello, WorldH!";
	
// 	size_t result = strspn(str1, str2);
// 	size_t result2 = ft_strspn(str1, str2);
// 	printf("Original strspn function:\n");
// 	printf("The initial segment with characters from str2 is %zu characters long.\n", result);
// 	printf("\nFt strspn function:\n");
// 	printf("The initial segment with characters from str2 is %zu characters long.\n", result2);	
// 	return 0;
// }