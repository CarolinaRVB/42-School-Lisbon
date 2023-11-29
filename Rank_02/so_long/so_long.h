/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:38:10 by crebelo-          #+#    #+#             */
/*   Updated: 2023/11/29 16:41:39 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx_linux/mlx.h"
# include "libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define TITLE "Plancton"
# define BACKGROUND "imgs/Background.xpm"
# define TILES "imgs/Tiles.xpm"
# define PLAYER "imgs/P.xpm"
# define PLAYER1 "imgs/P2.xpm"
# define PLAYER2 "imgs/P3.xpm"
# define PLAYER3 "imgs/P4.xpm"
# define PLAYER1L "imgs/P2L.xpm"
# define PLAYER2L "imgs/P3L.xpm"
# define PLAYER3L "imgs/P4L.xpm"
# define PLAYER5 "imgs/P5.xpm"
# define PLAYER6 "imgs/P6.xpm"
# define PLAYER7 "imgs/P8.xpm"
# define COLLECT "imgs/col.xpm"
# define EXIT "imgs/exit.xpm"
# define ENEMY "imgs/En.xpm"
# define TIME 99990
# define PIXEL_SIZE 55
# define KEY_ESC 65307
# define ARROW_RIGHT 65363
# define ARROW_LEFT 65361
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define KEY_D 100
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define MLX_ERROR 1

typedef struct s_map
{
	char	**outline;
	int		height;
	int		width;
	int		x;
	int		y;
}	t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*p;
	void	*p1;
	void	*p2;
	void	*p3;
	void	*p1l;
	void	*p2l;
	void	*p3l;
	void	*p5;
	void	*p6;
	void	*p7;
	void	*e;
	void	*x;
	void	*c;
	void	*t;
	void	*b;
	int		player;
	int		player_x;
	int		player_x_pre;
	int		player_y;
	int		player_y_pre;
	int		exit;
	int		exit_x;
	int		exit_y;
	int		collectible;
	int		move_count;
	t_map	*map;
}	t_game;

// so long utils 1
int		error_exit(char *str);
void	free_map(t_map *map);
int		free_game(t_game *game, char *str);
void	close_game(t_game *game, char *msg);

// so long utils 2
int		get_map_height(char *av);
int		keypress(int key, t_game *game);
int		destroy_x(t_game *game);
int		destroy(t_game *game, char *msg);
int		loop_hook(t_game *game);
void	display_count(t_game *game, int count);

// so long utils 3
void	move_animation_right(t_game *game, int x, int x_pre, int y);
void	move_animation_left(t_game *game, int x, int x_pre, int y);
void	move_animation_up(t_game *game, int x, int y, int y_pre);
void	move_animation_down(t_game *game, int x, int y, int y_pre);

// so long build
int		build_map(t_game *game, char *av);

// so long check
int		strcmpchrs(char **str, char *chrs, int height);
int		checknrplayers(t_game *game, int height);
int		check_map(t_game *game);

// int		mapwalls(t_game *game);
int		mapwalls(t_game *game, int len, int i);

// so long init
int		initiate_game(t_game *game);
void	populate_map(t_game *game, void *img);
#endif
