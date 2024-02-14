/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:19:57 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/14 07:16:54 by akuburas         ###   ########.fr       */
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

void	initialize_stacks(long *stack_a, long *stack_b, int argc, char **argv);
char	**join2darrays(char **arr1, char **arr2);
void	ft_free_substrings(char ***arr_str);
void	exit_handler(int error);

#endif