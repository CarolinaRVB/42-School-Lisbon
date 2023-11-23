/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:35:26 by crebelo-          #+#    #+#             */
/*   Updated: 2023/11/22 12:29:59 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (error_exit("Error: wrong number of arguments"));
	if (ft_checkfileext(av[1], ".ber") != 0)
		return (error_exit("Error: wrong file type"));
	if (build_map(&game, av[1]) != 0)
		return (1);
	if (check_map(&game) != 0)
		return (1);
	if (initiate_game(&game) != 0)
		return (1);
	return (0);
}
