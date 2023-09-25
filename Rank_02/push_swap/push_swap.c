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

int main(int ac, char *av[])
{
	//fix in case of arguments being passed as a string
	char	**args;
	args = av;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return(error_exit());
	else if (ac == 2)
		args = ft_split(av[1]);
	if (valid_av(args, ac) != 0 || valid_int(args, ac) != 0 || no_dup(args, ac) != 0)
		return(error_exit());

	
	printf("sucess");
	return (0);	
}