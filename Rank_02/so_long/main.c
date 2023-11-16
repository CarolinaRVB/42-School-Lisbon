/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:35:26 by crebelo-          #+#    #+#             */
/*   Updated: 2023/11/16 11:03:53 by crebelo-         ###   ########.fr       */
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
	}
	close(fd);
	return (i);
}

int	build_map(t_game *game, char *av)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(av, O_RDONLY);
	if (!fd)
	{
		ft_printf("Error: file error");   //call function to printf and free memmory
		return (1);
	}
	i = 0;
	game->map = malloc(sizeof(t_map));
	game->map->width = 0;
	game->map->height = get_map_height(av);
	game->map->outline = ft_calloc(game->map->height + 1, sizeof(char *));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (game->map->width == 0)
			game->map->width = ft_strlen_nl(line);
		else if (game->map->width != (int)ft_strlen_nl(line))
			return (error_exit("Error: invalid map size", game));
		game->map->outline[i] = ft_strdup(line);
		i++;
	}
	close(fd);
	return (0);
}

void display_image(t_game *game, char *image_path, int x, int y)
{
	int	img_height;
	int	img_width;
	void *img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, image_path, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img_ptr, x, y);
}


void	populate_map(t_game *game)
{
	for (int y = 0; y < game->map->height; ++y)
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

// map rules before build
// 1 - check if it has walls (1)- first and last lines must contain only char 1
// 	 - first and last character before each newline must contain only char 1
// 2 - check if it's rectangular - cannot have one line/collumn bigger than the rest.
// 3 - file has to be .ber file
// 4 - must contain 1 exit, 1 playler, collectible >= 1, 0's for floors
// 5 - other characters outside of what i use, must be error
// 4 - create function for error exit

// int	check_walls;
// int	check_players;
// if (strcmpchrs(game->map->outline, "01PEC\n") != 0)
// 		return(error_exit("Error: wrong map players", game));
		// printf("%c\n", str[i][j]);
		// printf("%c\n", chrs[k]);
int	strcmpchrs(char **str, char *chrs)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
	
		while (str[i][j] != '\0')
		{
			k = 0;
			printf("%c\n", str[i][j]);
			printf("%c\n", chrs[k]);
			while (str[i][j] != chrs[k])
				k++;
			if (chrs[k] == '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// int	strcmpchrs(char **str, char *chrs)
// {
// 	int	i;
// 	int	j;
// 	int	k;

// 	i = 0;
// 	j = 0;
// 	k = 0;
// 	while (str[i][j] != '\0')
// 	{
// 		j = 0;
// 		printf("%c\n", str[i][j]);
// 		printf("%c\n", chrs[k]);
// 		while (str[i][j] != '\0')
// 		{
// 			k = 0;
// 			while (str[i][j] != chrs[k])
// 				k++;
// 			if (chrs[k] == '\0')
// 				return (1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }
// {
//     int i = 0;
//     while (str[i] != NULL) {
//         if (strcmp(str[i], chrs) == 0) {
//             return 0; // Strings match
//         }
//         i++;
//     }
//     return 1; // Strings don't match
// }


int	check_map(t_game *game)
{
	// int	i;
	// int	j;
	// int	P;
	// int	E;
	// int	C;

	// i = 0;
	// j = 0;
	// P = 0;
	// E = 0;
	// C = 0;
	// if (check_map_outline(game) != 0)
	// 	error_exit("Error: wrong map structure\n", game);
	if (strcmpchrs(game->map->outline, "01PEC\n") != 0)
		return(error_exit("Error: wrong map players", game));
	// while (game->map->outline[i][j] != '\n')
	// {
	// 	j = 0;
	// 	while (game->map->outline[i][j] != '\n')
	// 	{
	// 		if (game->map->outline[i][j] == 'P')
	// 			P++;
	// 		if (game->map->outline[i][j] == 'E')
	// 			E++;
	// 		if (game->map->outline[i][j] == 'C')
	// 			C++;
	// 		j++;
	// 	}
	// 	i++;
	// }
	// if (P != 1 && E != 1)
	// 	error_exit("Error: wrong number of players\n", game);
	// if (C < 1)
	// 	error_exit("Error: no colectibles\n", game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (1);
	if (ft_checkfileext(av[1], ".ber") != 0)
	{
		printf("Error: wrong file type\n");
		return (1);	
	}
	if (build_map(&game, av[1]) != 0)
		return (1);
	if (check_map(&game) == 1)
		return (1);

	// for (int i = 0; i < 5; ++i)
	// 	printf("%s", game.map->outline[i]);
	game.mlx_ptr = mlx_init();

	if (game.mlx_ptr == NULL)
		return (MLX_ERROR);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.map->width * PIXEL_SIZE, game.map->height * PIXEL_SIZE, TITLE);
	if (game.win_ptr == NULL)
	{
		free(game.win_ptr);
		return (MLX_ERROR);
	}
	populate_map(&game);
	mlx_loop(game.mlx_ptr);

	mlx_destroy_display(game.mlx_ptr);
	free(game.mlx_ptr);
}