/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_calculations_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:17:52 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/22 11:50:56 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	reset_rotate_counts(t_move_count *count)
{
	count->rotate_a = 0;
	count->rotate_b = 0;
}

static void	reset_reverse_rotate_counts(t_move_count *count)
{
	count->reverse_rotate_a = 0;
	count->reverse_rotate_b = 0;
}

static void	compare_and_reset_counts(t_move_count *count)
{
	if (count->rotate_a < count->reverse_rotate_a)
		count->reverse_rotate_a = 0;
	else
		count->rotate_a = 0;
	if (count->rotate_b < count->reverse_rotate_b)
		count->reverse_rotate_b = 0;
	else
		count->rotate_b = 0;
}

static void	all_values_exist(t_move_count *count, int ist, int rt, int rrt)
{
	if (ist < rt && ist < rrt)
		compare_and_reset_counts(count);
	else if (rt < rrt)
		reset_reverse_rotate_counts(count);
	else
		reset_rotate_counts(count);
}

void	pre_sort(t_move_count *count, int ist, int rt, int rrt)
{
	if (rt != -1 && rrt != -1)
		all_values_exist(count, ist, rt, rrt);
	else if (rt == -1)
	{
		if (ist < rrt)
			compare_and_reset_counts(count);
		else
			reset_reverse_rotate_counts(count);
	}
	else if (rrt == -1)
	{
		if (ist < rt)
			compare_and_reset_counts(count);
		else
			reset_reverse_rotate_counts(count);
	}
	else
		compare_and_reset_counts(count);
}
