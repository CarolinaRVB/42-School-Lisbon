/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:26:04 by crebelo-          #+#    #+#             */
/*   Updated: 2023/09/10 20:26:04 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int	count_words(char *str)
{
	int	i = 0;
	int	word = 0;
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
	int 	j = i - start;
	char	*word = (char *)malloc(sizeof(char *) * j + 1);
	int	n = 0;
	
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
	int nwords = count_words(str);
	int	i = 0;
	int	j = 0;
	int start = 0;
	char **ar;

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
		ar[j] = add_word(str, start, i);
		j++;
		i++;		
	}
	ar[j] = NULL;
	return (ar);
}

// int	main()
// {
// 	char	*str = "  starting and ending   " ;
// 	char	**split = ft_split(str);
// 	int	i = 0;

// 	while (split[i] != NULL)
// 	{
// 		printf("%s\n", split[i]);
// 		i++;
// 	}
	
// }