/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:24:54 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/03 17:24:54 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include <stdio.h>

char	*ft_strrev(char *str)
{
	int 	i;
	int		len;
	int		count;
	char	tmp;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	if (len % 2 == 0)
		count = len / 2;
	else
		count = len / 2 + 1;
	while (count-- > 0)
	{
		tmp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = tmp;
		i++;
		len--;
	}
	return (str);
}

// int	main()
// {
// 	char input[] = "Hell world";
// 	printf("Original string: %s\n", input);

// 	// Reverse the string using ft_strrev
// 	ft_strrev(input);

// 	printf("Reversed string: %s\n", input);

// 	return 0;
// }