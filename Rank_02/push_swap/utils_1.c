/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:09:01 by crebelo-          #+#    #+#             */
/*   Updated: 2023/09/24 15:09:01 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char *av)
{
	int i;

	i = 0;
	if (av[0] == '-')
		i++;
	while (av[i] != '\0')
	{
		if (av[i] >= '0' && av[i] <= '9')
		{
			i++;
		}	
		else
			return (1);
	}
	return (0);
}

long int	ft_atoll(char *str)
{
	long int	i;
	long int	res;
	long int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	
	return (res * sign);
}

int	count_words(char *str)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
			i++;
		if (str[i] != '\0' && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			word++;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			i++;
	}
	return (word);
}

char	*add_word(char *str, int start, int i)
{
	int 	j;
	char	*word;
	int		n;
	
	j = i - start;
	n = 0;
	word = (char *)malloc(sizeof(char *) * j + 1);
	if (!word)
		return (NULL);
	while (str[start] != '\0' && start <= i)
	{
		word[n] = str[start];
		n++;
		start++;
	}
	word[n] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	int 	nwords;
	int		i;
	int		j;
	int 	start;
	char 	**ar;

	nwords = count_words(str);
	i = 0;
	j = 0;
	ar = malloc(sizeof(char *) * nwords + 1);
	if (!ar)
		return (NULL);
	while (str[i] != '\0' && j < nwords)
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
			i++;
		start = i;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			i++;
		i--;
		ar[j++] = add_word(str, start, i);
		i++;		
	}
	ar[j] = NULL;
	return (ar);
}