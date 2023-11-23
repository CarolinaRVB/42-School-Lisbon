/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:48:43 by crebelo-          #+#    #+#             */
/*   Updated: 2023/11/20 17:18:23 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void display_image(t_game *game, char *image_path, int x, int y)
{
	int	img_height;
	int	img_width;
	void *img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, image_path, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img_ptr, x, y);
}


void	populate_map(t_game *game)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	for (y = 0; y < game->map->height; ++y)
	{
		for (int x = 0; x < game->map->width; ++x)
		{
			if (game->map->outline[y][x] == '1')
			{
				// Adjust x and y positions based on your requirements
				int image_x = x * PIXEL_SIZE;
				int image_y = y * PIXEL_SIZE;
				display_image(game, "Tiles.xpm", image_x, image_y);
			}
			else if (game->map->outline[y][x] == '0')
			{
				// Adjust x and y positions based on your requirements
				int image_x = x * PIXEL_SIZE;
				int image_y = y * PIXEL_SIZE;
				display_image(game, "Background.xpm", image_x, image_y);
			}
			else if (game->map->outline[y][x] == 'P')
			{
				// Adjust x and y positions based on your requirements
				int image_x = x * PIXEL_SIZE;
				int image_y = y * PIXEL_SIZE;
				display_image(game, "char.xpm", image_x, image_y);
			}
			else if (game->map->outline[y][x] == 'C')
			{
				// Adjust x and y positions based on your requirements
				int image_x = x * PIXEL_SIZE;
				int image_y = y * PIXEL_SIZE;
				display_image(game, "col.xpm", image_x, image_y);
			}
			else if (game->map->outline[y][x] == 'E')
			{
				// Adjust x and y positions based on your requirements
				int image_x = x * PIXEL_SIZE;
				int image_y = y * PIXEL_SIZE;
				display_image(game, "exit.xpm", image_x, image_y);
			}
		}
	}
}