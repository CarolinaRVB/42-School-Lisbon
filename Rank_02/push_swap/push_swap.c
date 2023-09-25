/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:44:39 by crebelo-          #+#    #+#             */
/*   Updated: 2023/09/23 10:44:39 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <unistd.h>
#include<stdio.h>
int	error_exit()
{
	write(1, "Error\n", 6);
	return (1);
}

int	valid_av(char **av, int size)
{
	int	i = 1;
	
	while(i < size - 1)
	{
		if(is_digit(av[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int valid_int(char **av, int size)
{
	int	i = 1;
	int	n;
	while(i < size - 1)
	{
		n = ft_atoi(av[i]);
		if (n > 2147483647)
			return (1);
		if (n < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int	no_dup(char **av, int size)
{
	int i = 1;
	while (i < size - 1)
	{	
		if(check_doubles(av, *av[i], i) != 0)
			return (1);
		i++;
	}
	return (0);
}

int main(int ac, char *av[])
{
	if (ac < 2 || valid_av(av, ac) != 0)
		return(error_exit());
	// if (valid_int(&av, ac) != 0 || no_dup(&av, ac) != 0)  //confirmar se colocando por ordem na mesma linha funciona
	// 	error_exit();
	printf("sucess");
	return (0);	
}