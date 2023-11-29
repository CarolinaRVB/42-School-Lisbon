/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_build.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:50:05 by crebelo-          #+#    #+#             */
/*   Updated: 2023/11/29 10:46:52 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_height(char *av)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(av, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

void	init_imgs(t_game *game)
{
	game->p = NULL;
	game->p1 = NULL;
	game->p2 = NULL;
	game->p3 = NULL;
	game->p1l = NULL;
	game->p2l = NULL;
	game->p3l = NULL;
	game->p5 = NULL;
	game->p6 = NULL;
	game->p7 = NULL;
	game->e = NULL;
	game->x = NULL;
	game->c = NULL;
	game->t = NULL;
	game->b = NULL;
}

int	init_struct(t_game *game, int fd, char *av)
{
	if (!fd)
		return (error_exit("Error: error opening file"));
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (error_exit("Error: error allocating"));
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	init_imgs(game);
	game->move_count = 0;
	game->map->width = 0;
	game->map->x = 0;
	game->map->y = 0;
	game->map->height = get_map_height(av);
	game->map->outline = ft_calloc(game->map->height, sizeof(char *));
	if (!game->map->outline)
		return (free_game(game, "Error: error building"));
	return (0);
}

int	build_map(t_game *game, char *av)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(av, O_RDONLY);
	if (init_struct(game, fd, av) != 0)
		return (1);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map->outline[i] = ft_strdup(line);
		if (!game->map->outline[i++])
		{
			free(line);
			return (free_game(game, "Error: error building"));
		}
		free(line);
	}
	close(fd);
	return (0);
}
