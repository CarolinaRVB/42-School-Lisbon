/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:56:27 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/04 17:56:27 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (reject[j] != '\0')
		{
			if (s[i] == reject[j])
				return (i);
			else
				j++;
		}
		j = 0;
		i++;
	}
	return (i);
}

int main() {
    const char str1[] = "Hello, World!";
    const char str2[] = "Woe";
    
    size_t result = ft_strcspn(str1, str2);
    printf("The initial segment without characters from str2 is %zu characters long.\n", result);

	size_t result2 = strcspn(str1, str2);
	printf("The initial segment without characters from str2 is %zu characters long.\n", result2);

	return 0;
}