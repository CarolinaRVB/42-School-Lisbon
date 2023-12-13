/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:46:51 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/06/29 11:07:48 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(long tmp, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi_max(av[i]) == tmp)
			return (1);
		i++;
	}
	return (0);
}

void	validator(char **av, t_stack **stack_a)
{
	int		i;
	long	tmp;

	i = 0;
	while (av[++i])
	{
		tmp = ft_atoi_max(av[i]);
		if (!valid_num_str(av[i]) || check_dup(tmp, av, i))
		{
			free_list((*stack_a));
			error_msg();
		}
		if (!(*stack_a))
			insert_front(stack_a, tmp);
		else
			insert_end(stack_a, tmp);
	}
}
