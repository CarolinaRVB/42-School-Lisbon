/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:32:20 by crebelo-          #+#    #+#             */
/*   Updated: 2023/07/18 20:32:20 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int	ft_count_underscores(char *str)
{
	int	i = 0;
	int	count = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '_')
			count++;
		i++;
	}
	return (count);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

char	*ft_convert(char *str)
{
	int	i;
	int	j;
	int	count;
	char	*s;

	i = ft_strlen(str);
	count = ft_count_underscores(str);
	s = (char *)malloc((i - count + 1) * (sizeof(char)));
	if (!s)
		return (0);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '_')
			s[j] = str[++i] - 32;
		else
			s[j] = str[i];
		i++;
		j++;
	}
	s[j] = '\0';
	return (s);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return  (0);
	}

	char	*str;
	int	i;

	i = 0;
	str = ft_convert(argv[1]);
	ft_putstr(str);
	free(str);

	return (0);	
}