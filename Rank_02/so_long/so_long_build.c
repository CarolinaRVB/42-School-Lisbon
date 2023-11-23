/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_build.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:50:05 by crebelo-          #+#    #+#             */
/*   Updated: 2023/11/23 13:04:10 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	build_map(t_game *game, char *av)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(av, O_RDONLY);
	if (!fd)
		return(error_exit("Error: error opening file"));
	i = 0;
	game->map = malloc(sizeof(t_map));
	game->move_count = 0;
	if (!game->map)
		return(error_exit("Error: error allocating"));
	game->map->width = 0;
	game->map->height = get_map_height(av);
	game->map->outline = ft_calloc(game->map->height, sizeof(char*));
	if (!game->map->outline)
		return(free_game(game, "Error: error building"));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (game->map->width == 0)
			game->map->width = ft_strlen_nl(line);
		game->map->outline[i] = ft_strdup(line);
		if (!game->map->outline[i])
		{
			free(line);
			return(free_game(game,  "Error: error building"));			
		}
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
