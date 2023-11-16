/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:38:10 by crebelo-          #+#    #+#             */
/*   Updated: 2023/11/13 18:18:38 by crebelo-         ###   ########.fr       */
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

# define PIXEL_SIZE 60

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
	t_map	*map;
	// t_img	*imgs;
}	t_game;

#endif