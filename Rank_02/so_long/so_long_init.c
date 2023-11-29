/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:06:20 by crebelo-          #+#    #+#             */
/*   Updated: 2023/11/29 10:57:26 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_game *game)
{
	int		h;
	int		w;

	h = PIXEL_SIZE;
	w = PIXEL_SIZE;
	game->p1 = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER1, &w, &h);
	game->p2 = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER2, &w, &h);
	game->p3 = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER3, &w, &h);
	game->p1l = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER1L, &w, &h);
	game->p2l = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER2L, &w, &h);
	game->p3l = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER3L, &w, &h);
	game->p5 = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER5, &w, &h);
	game->p6 = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER6, &w, &h);
	game->p7 = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER7, &w, &h);
}

void	init_imgs_files(t_game *game)
{
	int		h;
	int		w;

	h = PIXEL_SIZE;
	w = PIXEL_SIZE;
	init_player(game);
	game->p = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER, &w, &h);
	game->e = mlx_xpm_file_to_image(game->mlx_ptr, EXIT, &w, &h);
	game->c = mlx_xpm_file_to_image(game->mlx_ptr, COLLECT, &w, &h);
	game->x = mlx_xpm_file_to_image(game->mlx_ptr, ENEMY, &w, &h);
	game->t = mlx_xpm_file_to_image(game->mlx_ptr, TILES, &w, &h);
	game->b = mlx_xpm_file_to_image(game->mlx_ptr, BACKGROUND, &w, &h);
}

void	populate_map(t_game *game, void	*img)
{
	while (game->map->y < game->map->height)
	{
		game->map->x = 0;
		while (game->map->x < game->map->width)
		{
			if (game->map->outline[game->map->y][game->map->x] == 'P')
				img = game->p;
			if (game->map->outline[game->map->y][game->map->x] == 'E')
				img = game->e;
			if (game->map->outline[game->map->y][game->map->x] == 'C')
				img = game->c;
			if (game->map->outline[game->map->y][game->map->x] == 'X')
				img = game->x;
			if (game->map->outline[game->map->y][game->map->x] == '0')
				img = game->b;
			if (game->map->outline[game->map->y][game->map->x] == '1')
				img = game->t;
			if (img)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img,
					game->map->x * PIXEL_SIZE, game->map->y * PIXEL_SIZE);
			game->map->x = game->map->x + 1;
		}
		game->map->y = game->map->y + 1;
	}
}

int	initiate_game(t_game *game)
{
	void	*img;

	img = NULL;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map->width * PIXEL_SIZE,
			game->map->height * PIXEL_SIZE, TITLE);
	if (game->win_ptr == NULL)
	{
		free(game->win_ptr);
		free_game(game, "Error: error building window");
		return (1);
	}
	init_imgs_files(game);
	populate_map(game, img);
	display_count(game, 0);
	mlx_hook(game->win_ptr, 2, 1L << 0, keypress, game);
	mlx_hook(game->win_ptr, 17, 0, destroy_x, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
