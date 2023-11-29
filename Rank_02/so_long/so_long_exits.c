/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_exits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:19:27 by crebelo-          #+#    #+#             */
/*   Updated: 2023/11/29 10:19:27 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(t_game *game, char *msg)
{
	close_game(game, msg);
	exit(0);
}

int	destroy_x(t_game *game)
{
	close_game(game, "Closing the game");
	return (0);
}

int	error_exit(char *str)
{
	ft_printf("%s\n", str);
	return (1);
}
