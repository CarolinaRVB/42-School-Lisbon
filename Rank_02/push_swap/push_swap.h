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
# include <stdio.h>


typedef struct s_list
{
	int			    content;
	int				index;
	
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
int	list_size(t_list **stack);
void	ft_add_node(t_list **lst, char *str, int index);
void	reset_index(t_list **stack);
int	is_sorted(t_list **stack);
void	sort_list(t_list **a, t_list **b, int size);
void	small_sort(t_list **a, t_list **b);
void	big_sort(t_list **a, t_list **b);
void	sa(t_list **lst);
void	ra(t_list **lst);
void 	rra(t_list **lst);
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*is_min(t_list **lst);

void	five_sort(t_list **a, t_list **b);
void	four_sort(t_list **a, t_list **b);
void	three_sort(t_list **a, t_list **b);



#endif