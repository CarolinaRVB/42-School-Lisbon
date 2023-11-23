/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:45:41 by crebelo-          #+#    #+#             */
/*   Updated: 2023/11/20 09:53:08 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int error_exit(char *str)
{
	ft_printf("%s\n", str);
	return (1);
}

void free_map(t_map *map) 
{
	int	i;

	i = 0;
	if (map)
	{
		if (map->outline)
		{
			while (i < map->height)
			{
				free(map->outline[i]);
				i++;
			}
			free(map->outline);
			map->outline = NULL;
		}
		free(map);
	}
}

int free_game(t_game *game, char *str)
{
	if (str)
		printf("%s\n", str);
	if (game)
	{
		if (game->map)
		{
			free_map(game->map);
			game->map = NULL;
		}
	}
	return (1);
}
