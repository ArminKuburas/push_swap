/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:19:57 by akuburas          #+#    #+#             */
/*   Updated: 2024/03/01 14:14:53 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/libft.h"

enum e_errors
{
	WRONG_AMOUNT_OF_ARGUMENTS = 1,
	MALLOC_ERROR = 2,
	WRONG_ARGUMENTS = 3
};

typedef struct s_new_count
{
	int	rotate_a;
	int	rotate_a_again;
	int	swap_a;
	int	push_cost;
	int	reverse_rotate_a;
	int	reverse_rotate_a_again;
	int	reduce;
	int	total;
}	t_new_count;

typedef struct s_move_count
{
	int		rotate_a;
	int		rotate_b;
	int		rotate_both;
	int		reverse_rotate_a;
	int		reverse_rotate_b;
	int		reverse_rotate_both;
	int		total;
}	t_m_count;

typedef struct s_stack_info
{
	int		amount_of_elements;
	int		amount_of_elements_a;
	int		amount_of_elements_b;
	long	min_a;
	long	min_b;
	long	max_a;
	long	max_b;
}	t_data;

void		init_stacks(long **stack_a, long **stack_b, int argc, char **argv);
char		**join2darrays(char **old_arr, char **arr1, char **arr2);
void		ft_free_substrings(char ***arr_str);
void		exit_handler(int error);
void		swap_a(long *stack_a);
void		swap_b(long *stack_b);
void		swap_both(long *stack_a, long *stack_b);
void		rotate_a(long *stack_a, int rr);
void		rotate_b(long *stack_b, int rr);
void		rotate_both(long *stack_a, long *stack_b);
void		reverse_rotate_a(long *stack_a, int rr);
void		reverse_rotate_b(long *stack_b, int rr);
void		reverse_rotate_both(long *stack_a, long *stack_b);
void		push_into_a(long *stack_a, long *stack_b);
void		push_into_b(long *stack_a, long *stack_b);
void		sort_stack(long **stack_a, long **stack_b);
void		initial_sort(long **stack_a, long **stack_b, t_data *data);
void		final_calculations(t_m_count *count);
void		use_rotate(t_m_count cheapest, long **stack_a, long **stack_b);
void		use_rev_rotate(t_m_count cheapest, long **stack_a, long **stack_b);
int			count_elements(long *array);
void		push_back(long *stack_a, long *stack_b, t_data *data);
int			find_the_number_min(long number, long *array, long min);
void		sort_three(long **stack_a);
void		pre_sort(t_m_count *count, int ist, int rt, int rrt);
void		print_stack(long *stack_a, long *stack_b, t_data *data);
int			find_the_number(long *array, int max, long number);
void		push_cheapest(long **stack_a, long **stack_b, t_data *data);
void		array_cost_max(long *array, t_m_count *count, long max);
void		array_cost(long number, long *array, t_m_count *count, long max);
t_m_count	push_cost(long *stack_a, long *stack_b, int i, t_data *data);
int			check_arguments(char **args);
int			stack_allocator(long **stack_a, long **stack_b, int amount_of_args);
int			argument_creator(int argc, char **argv, char ***args);
void		sort_small_stack(long **stack_a, int amount_of_elements);
void		initial_sort(long **stack_a, long **stack_b, t_data *data);
void		check_order(long *stack_a, long min_value, int amount);
void		sort_three(long **stack_a);
void		initial_push(long *stack_a, long *stack_b, t_data *data);
int			turn_into_stack(long **stack_a, char **args);
int			check_if_empty(int argc, char **argv);

#endif