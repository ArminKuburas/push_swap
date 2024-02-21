/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:39:42 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/21 20:12:29 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	final_calculations(t_move_count *count)
{
	if (count->rotate_a > count->rotate_b)
	{
		count->rotate_both = count->rotate_b;
		count->rotate_b = 0;
		count->rotate_a -= count->rotate_both;
	}
	else if (count->rotate_a < count->rotate_b)
	{
		count->rotate_both = count->rotate_a;
		count->rotate_a = 0;
		count->rotate_b -= count->rotate_both;
	}
	if (count->reverse_rotate_a > count->reverse_rotate_b)
	{
		count->reverse_rotate_both = count->reverse_rotate_b;
		count->reverse_rotate_b = 0;
		count->reverse_rotate_a -= count->reverse_rotate_both;
	}
	else if (count->reverse_rotate_a < count->reverse_rotate_b)
	{
		count->reverse_rotate_both = count->reverse_rotate_a;
		count->reverse_rotate_a = 0;
		count->reverse_rotate_b -= count->reverse_rotate_both;
	}
}

void	use_rotate(t_move_count cheapest, long **stack_a, long **stack_b)
{
	while (cheapest.rotate_a > 0)
	{
		rotate_a(*stack_a, 0);
		cheapest.rotate_a--;
	}
	while (cheapest.rotate_b > 0)
	{
		rotate_b(*stack_b, 0);
		cheapest.rotate_b--;
	}
	while (cheapest.rotate_both > 0)
	{
		rotate_both(*stack_a, *stack_b);
		cheapest.rotate_both--;
	}
}

void	use_rev_rotate(t_move_count cheapest, long **stack_a, long **stack_b)
{
	while (cheapest.reverse_rotate_a > 0)
	{
		reverse_rotate_a(*stack_a, 0);
		cheapest.reverse_rotate_a--;
	}
	while (cheapest.reverse_rotate_b > 0)
	{
		reverse_rotate_b(*stack_b, 0);
		cheapest.reverse_rotate_b--;
	}
	while (cheapest.reverse_rotate_both > 0)
	{
		reverse_rotate_both(*stack_a, *stack_b);
		cheapest.reverse_rotate_both--;
	}
}

int	count_elements(long *array)
{
	int		i;

	i = 0;
	while (array[i] < 2147483648)
		i++;
	return (i);
}

void	sort_small_stack(long **stack_a, int amount_of_elements)
{
	if (amount_of_elements == 2)
	{
		if ((*stack_a)[0] > (*stack_a)[1])
			swap_a(*stack_a);
	}
	else if (amount_of_elements == 3)
		sort_three(stack_a);
}
