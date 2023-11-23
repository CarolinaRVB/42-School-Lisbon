/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:38:10 by crebelo-          #+#    #+#             */
/*   Updated: 2023/11/22 13:41:55 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "minilibx_linux/mlx.h"
#include "libft/libft.h"
#include <X11/X.h>
#include <X11/keysym.h>

# define TITLE "Plancton"
# define PIXEL_SIZE 55
# define KEY_ESC 65307
# define ARROW_RIGHT 65363
# define ARROW_LEFT 65361
# define ARROW_UP 65362
# define ARROW_DOWN 65364
#define MLX_ERROR 1

typedef struct s_map
{
	char	**outline;
	int		height;
	int		width;
}	t_map;


typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		player;
	int		player_x;
	int		player_x_pre;
	int		player_y;
	int		player_y_pre;
	int		exit;
	int		exit_x;
	int		exit_y;
	int		collectible;	
	t_map	*map;
	// t_img	*imgs;
}	t_game;

// so long utils 1
int 	error_exit(char *str);
void 	free_map(t_map *map);
int 	free_game(t_game *game, char *str);

// so long utils 2
int		get_map_height(char *av);
int		keypress(int key, t_game *game);
int		destroy(t_game *game);
int		loop_hook(t_game *game);


// so long build
int		build_map(t_game *game, char *av);

// so long check
int		strcmpchrs(char **str, char *chrs, int height);
int		checknrplayers(t_game *game, int height);
int		mapwalls(t_game *game);
int		check_map(t_game *game);

// so long init
int		initiate_game(t_game *game);
void	populate_map(t_game *game);
void	display_image(t_game *game, char *image_path, int x, int y);
#endif