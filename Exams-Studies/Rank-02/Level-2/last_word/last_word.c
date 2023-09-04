/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:50:20 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/08 13:50:20 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	int i;
	
	i = 0;
	while (argv[1][i] != '\0')
		i++;
	i--;
	while ((argv[1][i] < 33 || argv[1][i] > 126) && i != 0)
		i--;
	while (argv[1][i] >= 33 && argv[1][i] <= 126)
		i--;
	i++;
	while (argv[1][i] != '\0' && (argv[1][i] >= 33 && argv[1][i] <= 126))
	{
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}