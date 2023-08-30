/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:13:33 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/29 19:59:49 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write (1, "\n", 1);
		return (0);
	}

	int	i = 0;

	while (argv[1][i] < 33 && argv[1][i] > 126)
		i++;
	while (argv[1][i] != '\0' && argv[1][i] >= 33 && argv[1][i] <= 126)
		write(1, &argv[1][i++], 1);
	write(1, "\n", 1);

	return (0);
}
