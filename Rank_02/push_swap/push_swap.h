/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:14:05 by crebelo-          #+#    #+#             */
/*   Updated: 2023/09/23 12:14:05 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
#include<stdio.h>

int		is_digit(char *av);
int		valid_av(char **av, int size);
int		valid_int(char **av, int size);
int		no_dup(char **av, int size);
int	    error_exit();
long int		ft_atoll(char *str);
int	count_words(char *str);
char	*add_word(char *str, int start, int i);
char	**ft_split(char *str);

#endif