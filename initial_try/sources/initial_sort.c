/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:48:57 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/29 15:00:19 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	find_the_number(long *array, int max, long number)
{
	int		i;

	i = 0;
	while (array[i] != max)
	{
		if (number > array[i])
			break ;
		i++;
	}
	return (i);
}

static void	array_cost_max(long *array, t_move_count *count, long max)
{
	int	i;
	int	amount;

	i = 0;
	while (array[i] != max)
		i++;
	amount = count_elements(array);
	count->reverse_rotate_b = amount - i;
	count->rotate_b = i;
}

void	array_cost(long number, long *array, t_move_count *count, long max)
{
	int	i;
	int	lever;
	int	amount;

	i = 0;
	lever = 0;
	while (array[i] != max)
		i++;
	while (array[i] < 2147483648)
	{
		if (number > array[i])
		{
			lever = 1;
			break ;
		}
		i++;
	}
	if (lever == 0)
		i = find_the_number_max(array, max, number);
	amount = count_elements(array);
	count->reverse_rotate_b = amount - i;
	count->rotate_b = i;
}

static t_move_count	push_cost(long *stack_a, long *stack_b, int i, t_data *data)
{
	t_move_count	count;

	count = (t_move_count){};
	count.reverse_rotate_a = data->amount_of_elements_a - i;
	count.rotate_a = i;
	if (stack_a[i] > data->max_b)
		array_cost_max(stack_b, &count, data->max_b);
	else
		array_cost(stack_a[i], stack_b, &count, data->max_b);
	final_calculations(&count);
	count.total = count.rotate_a + count.rotate_b + count.rotate_both
		+ count.reverse_rotate_a + count.reverse_rotate_b
		+ count.reverse_rotate_both;
	return (count);
}

static void	push_cheapest(long **stack_a, long **stack_b, t_data *data)
{
	int				i;
	t_move_count	cheapest;
	t_move_count	tmp;

	i = 1;
	cheapest = push_cost(*stack_a, *stack_b, 0, data);
	while (i < data->amount_of_elements_a)
	{
		tmp = push_cost(*stack_a, *stack_b, i, data);
		if (tmp.total < cheapest.total)
			cheapest = tmp;
		i++;
	}
	use_rotate(cheapest, stack_a, stack_b);
	use_rev_rotate(cheapest, stack_a, stack_b);
	if (*stack_a[0] > data->max_b)
		data->max_b = *stack_a[0];
	if (*stack_a[0] < data->min_b)
		data->min_b = *stack_a[0];
	push_into_b(*stack_a, *stack_b);
}

void	initial_sort(long **stack_a, long **stack_b, t_data *data)
{
	while (data->amount_of_elements_a > 3)
	{
		push_cheapest(stack_a, stack_b, data);
		data->amount_of_elements_a--;
		data->amount_of_elements_b++;
	}
}
