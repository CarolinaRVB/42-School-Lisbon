/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:51:02 by crebelo-          #+#    #+#             */
/*   Updated: 2023/11/20 18:54:39 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	strcmpchrs(char **str, char *chrs, int height)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < height)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			k = 0;
			while (str[i][j] != chrs[k] && chrs[k] != '\0')
				k++;
			if (chrs[k] == '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	checknrplayers(t_game *game, int height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;	
	while (i < height)
	{
		j = 0;
		while (game->map->outline[i][j] != '\0')
		{
			if (game->map->outline[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				game->player++;
			}	
			if (game->map->outline[i][j] == 'E')
				game->exit++;
			if (game->map->outline[i][j] == 'C')
				game->collectible++;
			j++;
		}
		i++;
	}
	if (game->player != 1)
		return (free_game(game, "Error: wrong number of players\n"));
	if (game->exit != 1)
		return (free_game(game, "Error: wrong number of exits\n"));
	if (game->collectible < 1)
		return(free_game(game, "Error: no colectibles\n"));
	return (0);
}

int	mapwalls(t_game *game)
{
	
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < game->map->height)
	{
		if (len == 0)
			len = ft_strlen_nl(game->map->outline[i]);
		else if (len != (int)ft_strlen_nl(game->map->outline[i]))
			return(free_game(game, "Error: wrong map shape"));
		i++;
	}
	i = 0;
	while (game->map->outline[0][i] != '\0' && game->map->outline[game->map->height - 1][i] != '\0')
	{
		if (game->map->outline[0][i] != '1' || game->map->outline[game->map->height - 1][i] != '1')
			return(free_game(game, "Error: wrong map walls"));
		i++;
	}
	i = 0;
	while (i < game->map->height)
	{
		if (game->map->outline[i][0] != '1' || game->map->outline[i][game->map->width - 1] != '1')
			return(free_game(game, "Error: wrong map walls"));
		i++;
	}
	return (0);
}

int	check_map(t_game *game)
{
	game->player = 0;
	game->exit = 0;
	game->collectible = 0;
	if (mapwalls(game) != 0)
		return(1);
	if (strcmpchrs(game->map->outline, "01PEC\n", game->map->height) != 0)
		return(free_game(game, "Error: invalid map elements"));
	if (checknrplayers(game, game->map->height) != 0)
		return(1);
	return (0);
}