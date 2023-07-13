/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:33:19 by marvin            #+#    #+#             */
/*   Updated: 2023/07/05 14:33:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_nl(char *stash)
{
	size_t		i;

	if (stash == NULL)
		return (0);
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(char *stash, char *line)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*nline;

	len = 0;
	j = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (line == NULL)
		i = 0;
	else
		while (line[i])
			i++;
	nline = (char *)malloc((len + i + 1) * sizeof(char));
	if (nline == NULL)
		return (NULL);
	while (line && line[j])
	{
		nline[j] = line[j];
		j++;
	}
	i = 0;
	while (i < len)
	{
		nline[j] = stash[i];
		i++;
		j++;
	}
	nline[j] = '\0';
	return (nline);
}

void	ft_clean(char *stash)
{
	size_t	stash_len;
	size_t	len;
	size_t	i;

	len = 0;
	stash_len = 0;
	i = 0;
	if (stash == NULL)
		return ;
	while (stash[len])
	{
		if (stash[len] == '\n')
		{
			len++;
			break ;
		}
		len++;
	}
	while (stash[stash_len] != '\0')
		stash_len++;
	while (i < stash_len - len + 1)
	{
		stash[i] = stash[i + len];
		i++;
	}
	stash[i] = '\0';
	
}
