/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:11:03 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/04 16:11:03 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		write(1, "\n", 1);
		return (0);
	}

	int	n1;
	int n2;
	signed int	result;
	char	symb;

	n1 = atoi(argv[1]);
	n2 = atoi(argv[3]);
	symb = argv[2][0];

	if (symb == '+')
		result = n1 + n2;
	if (symb == '-')
		result = n1 - n2;
	if (symb == '/')
		result = n1 / n2;
	if (symb == '*')
		result = n1 * n2;
	if (symb == '%')
		result = n1 % n2;
	printf("%d\n", result);
	return (0);
}