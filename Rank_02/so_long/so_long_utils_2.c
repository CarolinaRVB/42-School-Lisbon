/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:47:08 by crebelo-          #+#    #+#             */
/*   Updated: 2023/11/22 13:18:23 by crebelo-         ###   ########.fr       */
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

void	close_game(t_game *game, char *msg)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free_game(game, msg);
	exit(0);
}

void	move_right(t_game *game, int *x, int *x_pre)
{
	int next_x;
	
	next_x = *x + 1; 
	if (game->map->outline[game->player_y][next_x] != '1'&& game->map->outline[game->player_y][next_x] != 'E')
	{
		*x_pre = *x;
		*x = next_x;
		if (game->map->outline[game->player_y][next_x] == 'C')
			game->collectible = game->collectible - 1;
		if (game->map->outline[game->player_y][next_x] == 'E' && game->collectible <= 0)
			destroy(game);
		display_image(game, "Background.xpm", *x_pre * PIXEL_SIZE, game->player_y * PIXEL_SIZE);
		display_image(game, "char.xpm", *x * PIXEL_SIZE, game->player_y * PIXEL_SIZE);
	}
	else if (game->map->outline[game->player_y][next_x] == 'E' && game->collectible <= 0)
		destroy(game);
}

void	move_left(t_game *game, int *x, int *x_pre)
{
	int next_x;
	
	next_x = *x - 1; 
	if (game->map->outline[game->player_y][next_x] != '1' && game->map->outline[game->player_y][next_x] != 'E')
	{
		*x_pre = *x;
		*x = next_x;
		if (game->map->outline[game->player_y][next_x] == 'C')
			game->collectible = game->collectible - 1;
		if (game->map->outline[game->player_y][next_x] == 'E' && game->collectible <= 0)
			destroy(game);
		display_image(game, "Background.xpm", *x_pre * PIXEL_SIZE, game->player_y * PIXEL_SIZE);
		display_image(game, "char.xpm", *x * PIXEL_SIZE, game->player_y * PIXEL_SIZE);
	}
	else if (game->map->outline[game->player_y][next_x] == 'E' && game->collectible <= 0)
		destroy(game);
}

void	move_up(t_game *game, int *y, int *y_pre)
{
	int next_y;
	
	next_y = *y - 1; 
	if (game->map->outline[next_y][game->player_x] != '1' && game->map->outline[next_y][game->player_x] != 'E')
	{
		*y_pre = *y;
		*y = next_y;
		if (game->map->outline[next_y][game->player_x] == 'C')
			game->collectible = game->collectible - 1;
		display_image(game, "Background.xpm", game->player_x * PIXEL_SIZE, *y_pre * PIXEL_SIZE);
		display_image(game, "char.xpm", game->player_x * PIXEL_SIZE, *y * PIXEL_SIZE);
	}
	else if (game->map->outline[next_y][game->player_x] == 'E' && game->collectible <= 0)
		destroy(game);
}

void	move_down(t_game *game, int *y, int *y_pre)
{
	int next_y;
	
	next_y = *y + 1; 
	if (game->map->outline[next_y][game->player_x] != '1' && game->map->outline[next_y][game->player_x] != 'E')
	{
		*y_pre = *y;
		*y = next_y;
		if (game->map->outline[next_y][game->player_x] == 'C')
			game->collectible = game->collectible - 1;
		display_image(game, "Background.xpm", game->player_x * PIXEL_SIZE, *y_pre * PIXEL_SIZE);
		display_image(game, "char.xpm", game->player_x * PIXEL_SIZE, *y * PIXEL_SIZE);
	}
	else if (game->map->outline[next_y][game->player_x] == 'E' && game->collectible <= 0)
		destroy(game);
}


int	keypress(int key, t_game *game)
{
	if (key == KEY_ESC)
		close_game(game, "Closing game");
	if (key == ARROW_RIGHT)
	{
		ft_printf("%s\n", "Clicking right movement");
		move_right(game, &(game->player_x), &(game->player_x_pre));
	}
	if (key == ARROW_LEFT)
	{
		ft_printf("%s\n", "Clicking left movement");
		move_left(game, &(game->player_x), &(game->player_x_pre));
	}
	if (key == ARROW_UP)
	{
		ft_printf("%s\n", "Clicking up movement");
		move_up(game, &(game->player_y), &(game->player_y_pre));
	}
	if (key == ARROW_DOWN)
	{
		ft_printf("%s\n", "Clicking down movement");
		move_down(game, &(game->player_y), &(game->player_y_pre));
	}
	return (0);
}

int	destroy(t_game *game)
{
	close_game(game, "Closing game");
	exit(EXIT_SUCCESS);
}

int loop_hook(t_game *game)
{
	// This function doesn't perform any operations
	// It's just a placeholder to avoid the Valgrind error for now
	(void)game;
	// Return 0 to keep the loop running
	return 0;
}
