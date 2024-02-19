/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:19:57 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/19 20:18:01 by akuburas         ###   ########.fr       */
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

typedef struct s_move_count
{
	int		rotate_a;
	int		rotate_b;
	int		rotate_both;
	int		reverse_rotate_a;
	int		reverse_rotate_b;
	int		reverse_rotate_both;
	int		total;
}	t_move_count;

typedef struct s_stack_info
{
	int		amount_of_elements;
	int		amount_of_elements_a;
	int		amount_of_elements_b;
	int		max_b;
	int		min_b;
}	t_data;

void	init_stacks(long **stack_a, long **stack_b, int argc, char **argv);
char	**join2darrays(char **old_arr, char **arr1, char **arr2);
void	ft_free_substrings(char ***arr_str);
void	exit_handler(int error);
void	swap_a(long *stack_a);
void	swap_b(long *stack_b);
void	swap_both(long *stack_a, long *stack_b);
void	rotate_a(long *stack_a);
void	rotate_b(long *stack_b);
void	rotate_both(long *stack_a, long *stack_b);
void	reverse_rotate_a(long *stack_a);
void	reverse_rotate_b(long *stack_b);
void	reverse_rotate_both(long *stack_a, long *stack_b);
void	push_a(long *stack_a, long *stack_b);
void	push_b(long *stack_a, long *stack_b);
void	sort_stack(long **stack_a, long **stack_b);


#endif