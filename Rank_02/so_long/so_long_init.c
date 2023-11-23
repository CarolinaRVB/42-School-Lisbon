/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:06:20 by crebelo-          #+#    #+#             */
/*   Updated: 2023/11/20 20:16:02 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void display_image(t_game *game, char *image_path, int x, int y)
{
	int	img_height;
	int	img_width;
	void *img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, image_path, &img_width, &img_height);
	if (x >= 0 && x < game->map->width * PIXEL_SIZE &&
        y >= 0 && y < game->map->height * PIXEL_SIZE)
	{
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img_ptr, x, y);
    }
}


void	populate_map(t_game *game)
{
	int	x;
	int y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->outline[y][x] == 'P')
				display_image(game, "char.xpm", x * PIXEL_SIZE, y * PIXEL_SIZE);
			if (game->map->outline[y][x] == 'E')
				display_image(game, "exit.xpm", x * PIXEL_SIZE, y * PIXEL_SIZE);
			if (game->map->outline[y][x] == 'C')
				display_image(game, "col.xpm", x * PIXEL_SIZE, y * PIXEL_SIZE);
			if (game->map->outline[y][x] == '0')
				display_image(game, "Background.xpm", x * PIXEL_SIZE, y * PIXEL_SIZE);
			if (game->map->outline[y][x] == '1')
				display_image(game, "Tiles.xpm", x * PIXEL_SIZE, y * PIXEL_SIZE);
			x++;
		}
		y++;
	}
}

int	initiate_game(t_game *game)
{
	game->mlx_ptr = NULL;
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map->width * PIXEL_SIZE, game->map->height * PIXEL_SIZE, TITLE);
	if (game->win_ptr == NULL)
	{
		free(game->win_ptr);
		free_game(game, "Error: error building window");
		return (1);
	}
	populate_map(game);
	mlx_loop_hook(game->mlx_ptr, loop_hook, game);
	mlx_hook(game->win_ptr, 2, 1L << 0, keypress, game);
	mlx_hook(game->win_ptr, 17, 0, destroy, game);
	
	mlx_loop(game->mlx_ptr);

	return (0);
}