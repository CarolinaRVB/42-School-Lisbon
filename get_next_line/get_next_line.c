/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:19:46 by marvin            #+#    #+#             */
/*   Updated: 2023/06/29 13:19:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
char	*get_next_line(int fd)
{
	static char		stash[BUFFER_SIZE + 1];
	char			*line;
	int				n;
	int				i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	line = NULL;
	while (!i)
	{
		if (!stash[0])
			n = read(fd, stash, BUFFER_SIZE);	
		if (n == -1)
			return (NULL);
		line = get_line(stash, line);
		i = find_nl(stash) + (stash == NULL);
		if (stash[0] == '\0')
			return (NULL);
		ft_clean(stash);
	}
	return (line);
}

int main(void) {
	int fd = open("example.txt", O_RDONLY);
	if (fd == -1) {
		perror("Failed to open file");
		return 1;
	}

	char *line;
	while ((line = get_next_line(fd)) != NULL) {
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return 0;
}