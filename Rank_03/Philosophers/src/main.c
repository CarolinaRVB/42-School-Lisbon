/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 22:19:10 by crebelo-          #+#    #+#             */
/*   Updated: 2024/03/25 09:41:53 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*caller()
{
	printf("Inside Thread\n");
	return (NULL);
}

int main(int argc, char **argv)
{
	pthread_t	t1;

	(void)argv;
	if (argc != 5)
		return (error_msg("Error: args required: 4, args provided: %d\n", argc));
	pthread_create(&t1, NULL, &caller, NULL);
	pthread_join(t1, NULL);
	
	return (0);
}
