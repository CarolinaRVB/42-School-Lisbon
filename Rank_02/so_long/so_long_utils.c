/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:45:41 by crebelo-          #+#    #+#             */
/*   Updated: 2023/11/15 13:07:51 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clearmap(char **map)
{
	if (map)
		free(map);
}

int error_exit(char *str, t_game *game)
{
	ft_printf("%s\n", str);
	ft_clearmap(game->map->outline);
	return (1);
}
