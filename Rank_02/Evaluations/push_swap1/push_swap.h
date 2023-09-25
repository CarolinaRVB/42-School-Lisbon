/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffilipe- <ffilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:11:10 by ffilipe-          #+#    #+#             */
/*   Updated: 2023/06/28 13:43:26 by ffilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack	t_stack;
typedef struct s_table	t_table;

struct					s_stack
{
	int					number;
	struct s_stack		*next;
	struct s_stack		*prev;
};

struct					s_table
{
	int					b_friend;
	int					best_number;
	int					best_cost;
};

int						ft_atoi_max(const char *str);
void					delete_node(t_stack **head, int key);
void					insert_end(t_stack **head, int data);
void					insert_front(t_stack **head, int data);
int						get_args_len(char **av);
void					check_params(int ac, char **av);
int						check_dup(long tmp, char **av, int i);
void					validator(char **av, t_stack **stack_a);
int						valid_num_str(char *s);
int						ft_is_digit(char c);
void					free_list(t_stack *head);
void					def_cases(t_stack *stack_a, t_stack *stack_b,
							t_table *t_info, int size);
void					swap_a(t_stack **stack_a);
void					error_msg(void);
void					swap_b(t_stack **stack_b);
void					swap_s(t_stack **stack_a, t_stack **stack_b);
void					rotate_a(t_stack **stack_a);
void					rotate_b(t_stack **stack_b);
void					reverse_rotate_a(t_stack **stack_a);
void					reverse_rotate_b(t_stack **stack_b);
void					reverse_rotate_r(t_stack **stack_a, t_stack **stack_b);
void					push_a(t_stack **stack_a, t_stack **stack_b);
void					push_b(t_stack **stack_b, t_stack **stack_a);
void					two_numbers_case(t_stack **stack_a);
void					three_random_numbers(t_stack **stack_a);
void					five_random_numbers(t_stack **stack_a,
							t_stack **stack_b);
void					four_random_numbers(t_stack **stack_a,
							t_stack **stack_b);
void					big_sort(t_stack **stack_a, t_stack **stack_b,
							t_table *t_info);
int						get_stack_sum(t_stack *stack_a);
void					print_list(t_stack **head);
int						stack_size(t_stack *stack);
int						get_distance(t_stack **head, int index);
int						get_friend(t_stack **stack_a, int ref);
void					move_top_a(t_stack **head, int distance);
void					move_top_b(t_stack **head, int distance);
int						get_min(t_stack **head);
int						get_max(t_stack **head);
int						check_sorted(t_stack **stack);
int						get_val_idx(t_stack **stack, int val);
int						get_move_cost(t_stack **stack, int value);
int						best_solution(t_stack **stack_a, t_stack **stack_b,
							t_table *t_info);
#endif
