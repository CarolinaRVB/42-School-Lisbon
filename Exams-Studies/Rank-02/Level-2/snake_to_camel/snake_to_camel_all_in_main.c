/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:10:55 by crebelo-          #+#    #+#             */
/*   Updated: 2023/07/19 12:10:55 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	
	int	i = 0;
	int	j;
	int	count = 0;
	char	*str;

	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == '_')
			count++;
		i++;
	}

	str = (char *)malloc((i - count + 1) * sizeof(char));
	if (!str)
		return 0;

	i = 0;
	j = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == '_')
			str[j] = argv[1][++i] - 32;
		else
			str[j] = argv[1][i];
		i++;
		j++;
	}
	str[j] = '\0';

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	free(str);

	return 0;
}