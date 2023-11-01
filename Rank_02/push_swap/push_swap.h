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
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				cost;

	struct s_list	*next;
	struct s_list	*target;
}					t_list;

void		free_argv(char **ar);
int			check_arguments(char **args, int ac, int n);
void		start_sort(t_list **stack_a, t_list **stack_b, int ac, int n);

int			is_digit(char *av);
int			valid_av(char **av, int size, int n);
int			valid_int(char **av, int size, int n);
int			no_dup(char **av, int size, int n);
int			error_exit(void);
long int	ft_atoll(char *str);
char		**ft_split(char const *s, char c);
int			count_words(char const *s, char c);
int			count_ar(char **str);

void		init_args(t_list **stack, char **av, int ac);
size_t		ft_strlen(const char *s);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);

void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
void		free_list(t_list **stack);
int			list_size(t_list **stack);
void		ft_add_node(t_list **lst, char *str, int index);
void		reset_lst(t_list **stack);
int			is_sorted(t_list **stack);
void		sort_list(t_list **a, t_list **b, int size, int reals);
void		small_sort(t_list **a, t_list **b, int size);
void		get_target_cost(t_list **a, t_list **b);
void		big_sort(t_list **a, t_list **b);
void		sa(t_list **lst);
void		ra(t_list **lst);
void		rb(t_list **lst);
void		rrb(t_list **lst);
void		rra(t_list **lst);
void		pb(t_list **a, t_list **b);
void		pa(t_list **a, t_list **b);
void		ss(t_list **a, t_list **b);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*is_min(t_list **lst);

void		five_sort(t_list **a, t_list **b, t_list *min);
void		four_sort(t_list **a, t_list **b);
void		three_sort(t_list **a);

t_list		*find_target(t_list *a, t_list *b);
int			cost_value(t_list *lst, int index);
t_list		*get_min_val(t_list *lst);
t_list		*get_max(t_list *lst);
t_list		*get_min(t_list *b);
void		sort_final(t_list **a);

void		rrr(t_list **a, t_list **b);
void		rr(t_list **a, t_list **b);
void		move_top(t_list **a, t_list **b, t_list *min, t_list *target);
void		move_top_rrr(t_list **a, t_list **b, t_list *min, t_list *target);
void		move_top_rr(t_list **a, t_list **b, t_list *min, t_list *target);
void		top_rrr_b(t_list **a, t_list **b, int m_dis, int t_dis);
void		top_rrr_a(t_list **a, t_list **b, int m_dis, int t_dis);
void		top_rr_b(t_list **a, t_list **b, int m_dis, int t_dis);
void		top_rr_a(t_list **a, t_list **b, int m_dis, int t_dis);
void		move_top_a(t_list **a, t_list *target);
void		move_top_b(t_list **b, t_list *target);

t_list		*find_median(t_list **a);
t_list		*find_next_big(t_list *a, t_list *max);
int			max_cost(int a, int b);
int			calc_cost(t_list *tmp, int lasta, int lastb);

#endif
