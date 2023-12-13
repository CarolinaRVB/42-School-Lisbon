/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:47:08 by crebelo-          #+#    #+#             */
/*   Updated: 2023/12/08 21:06:01 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_game *game, int *x, int *x_pre)
{
	int	next_x;

	next_x = *x + 1;
	if (game->player_y == game->ey && next_x == game->ex)
		destroy(game, "Oh no, you lost");
	if (game->map->outline[game->player_y][next_x] != '1'
		&& game->map->outline[game->player_y][next_x] != 'E')
	{
		*x_pre = *x;
		*x = next_x;
		if (game->map->outline[game->player_y][next_x] == 'C')
		{
			game->collectible = game->collectible - 1;
			game->map->outline[game->player_y][next_x] = '0';
		}
		move_animation_right(game, *x * PIXEL_SIZE, *x_pre * PIXEL_SIZE,
			game->player_y * PIXEL_SIZE);
	}
	else if (game->map->outline[game->player_y][next_x] == 'E'
		&& game->collectible <= 0)
		destroy(game, "You win! Congrats!");
}

void	move_left(t_game *game, int *x, int *x_pre)
{
	int	next_x;

	next_x = *x - 1;
	if (game->player_y == game->ey && next_x == game->ex)
		destroy(game, "Oh no, you lost");
	if (game->map->outline[game->player_y][next_x] != '1'
		&& game->map->outline[game->player_y][next_x] != 'E')
	{
		*x_pre = *x;
		*x = next_x;
		if (game->map->outline[game->player_y][next_x] == 'C')
		{	
			game->collectible = game->collectible - 1;
			game->map->outline[game->player_y][next_x] = '0';
		}
		move_animation_left(game, *x * PIXEL_SIZE, *x_pre * PIXEL_SIZE,
			game->player_y * PIXEL_SIZE);
	}
	else if (game->map->outline[game->player_y][next_x] == 'E'
		&& game->collectible <= 0)
		destroy(game, "You win! Congrats!");
}

void	move_up(t_game *game, int *y, int *y_pre)
{
	int	next_y;

	next_y = *y - 1;
	if (next_y == game->ey && game->player_x == game->ex)
		destroy(game, "Oh no, you lost");
	if (game->map->outline[next_y][game->player_x] != '1'
		&& game->map->outline[next_y][game->player_x] != 'E')
	{
		*y_pre = *y;
		*y = next_y;
		if (game->map->outline[next_y][game->player_x] == 'C')
		{
			game->collectible = game->collectible - 1;
			game->map->outline[next_y][game->player_x] = '0';
		}
		move_animation_up(game, game->player_x * PIXEL_SIZE,
			*y * PIXEL_SIZE, *y_pre * PIXEL_SIZE);
	}
	else if (game->map->outline[next_y][game->player_x] == 'E'
		&& game->collectible <= 0)
		destroy(game, "You win! Congrats!");
}

void	move_down(t_game *game, int *y, int *y_pre)
{
	int	next_y;

	next_y = *y + 1;
	if (next_y == game->ey && game->player_x == game->ex)
		destroy(game, "Oh no, you lost");
	if (game->map->outline[next_y][game->player_x] != '1'
		&& game->map->outline[next_y][game->player_x] != 'E')
	{
		*y_pre = *y;
		*y = next_y;
		if (game->map->outline[next_y][game->player_x] == 'C')
		{	
			game->collectible = game->collectible - 1;
			game->map->outline[next_y][game->player_x] = '0';
		}
		move_animation_down(game, game->player_x * PIXEL_SIZE,
			*y * PIXEL_SIZE, *y_pre * PIXEL_SIZE);
	}
	else if (game->map->outline[next_y][game->player_x] == 'E'
		&& game->collectible <= 0)
		destroy(game, "You win! Congrats!");
}

int	keypress(int key, t_game *game)
{
	if (key == KEY_ESC)
		close_game(game, "Closing game");
	if (key == ARROW_RIGHT || key == KEY_D)
	{
		display_count(game, ++game->move_count);
		move_right(game, &(game->player_x), &(game->player_x_pre));
	}
	if (key == ARROW_LEFT || key == KEY_A)
	{
		display_count(game, ++game->move_count);
		move_left(game, &(game->player_x), &(game->player_x_pre));
	}
	if (key == ARROW_UP || key == KEY_W)
	{
		display_count(game, ++game->move_count);
		move_up(game, &(game->player_y), &(game->player_y_pre));
	}
	if (key == ARROW_DOWN || key == KEY_S)
	{
		display_count(game, ++game->move_count);
		move_down(game, &(game->player_y), &(game->player_y_pre));
	}
	return (0);
}
