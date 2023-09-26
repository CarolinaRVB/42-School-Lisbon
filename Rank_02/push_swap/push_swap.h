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


typedef struct s_list
{
	long int			    content;
	struct s_list	*next;
}                   t_list;

int		is_digit(char *av);
int		valid_av(char **av, int size);
int		valid_int(char **av, int size);
int		no_dup(char **av, int size, int n);
int		check_dup(char *n1, char *n2);
int		error_exit(void);
long int		ft_atoll(char *str);
int		count_words(char *str);
char	*add_word(char *str, int start, int i);
char	**ft_split(char *str);
void	init_args(t_list **stack, char **av, int ac);
int		ft_strlen(char **str);

void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	free_list(t_list **stack);

#endif