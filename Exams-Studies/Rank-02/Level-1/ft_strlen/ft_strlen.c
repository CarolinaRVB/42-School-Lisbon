/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:26:16 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/02 15:26:16 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

// int main()
// {
// 	char	*str = "this is a sentence";
// 	int	len = 0;
// 	printf("Original strlen function:\n");
// 	printf("Len of string is: %ld\n", strlen(str));

// 	printf("\nft_strlen function:\n");
// 	printf("Len of string is: %d\n", ft_strlen(str));
// 	return 0;
// }
