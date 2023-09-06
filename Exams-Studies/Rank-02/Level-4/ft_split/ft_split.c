/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:26:21 by crebelo-          #+#    #+#             */
/*   Updated: 2023/09/05 16:26:21 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>


int	count_words(char *str)
{
	int	i = 0;
	int	count = 0;
	while(str[i] != '\0')
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			count++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	return (count);
}

char	*add_word(char *str, int start, int end)
{
	int	i = 0;
	
	char	*word = (char *)malloc(sizeof(char *) * (end - start + 1));
	
	while (str[start] != '\0' && start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';

	return (word);
}

char    **ft_split(char *str)
{
	int	nwords = count_words(str);
	int	i = 0;
	int	j = 0;
	char	**split = (char **)malloc(sizeof(char *) * (nwords + 1));
	if (!split)
		return (NULL);

	while (str[i] != '\0')
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		int start = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		split[j] = add_word(str, start, i);
		j++;
		i++;
	}
	split[j] = NULL;
	return (split);
}

// int main() {
// 	char *input = "This is a sample string for splitting"; // Replace with your own input string
	
// 	char **result = ft_split(input);

// 	// Print the split strings
// 	for (int i = 0; result[i] != NULL; i++) {
// 		printf("%s\n", result[i]);
// 		free(result[i]);  // Free memory allocated for each split string
// 	}

// 	free(result);  // Free memory allocated for the array of split strings

// 	return 0;
// }