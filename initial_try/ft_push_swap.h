/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:19:57 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/16 10:23:51 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"

enum e_errors
{
	WRONG_AMOUNT_OF_ARGUMENTS = 1,
	MALLOC_ERROR = 2,
	WRONG_ARGUMENTS = 3
};

typedef struct s_stack_info
{
	int		amount_of_elements;
	int		amount_of_elements_a;
	int		amount_of_elements_b;
	int		max_b;
	int		min_b;
	int		move_cost;
}	t_data;

void	init_stacks(long **stack_a, long **stack_b, int argc, char **argv);
char	**join2darrays(char **old_arr, char **arr1, char **arr2);
void	ft_free_substrings(char ***arr_str);
void	exit_handler(int error);

#endif