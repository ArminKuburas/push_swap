/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:33:37 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/21 11:52:02 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	array_cost_max_b(long *array, t_move_count *count, long min)
{
	int	i;
	int	amount;

	i = 0;
	while (array[i] != min)
		i++;
	amount = count_elements(array);
	if (amount - i < i)
		count->reverse_rotate_a = amount - i;
	else
		count->rotate_a = i;
}

void	array_cost_min(long *array, t_move_count *count, long min)
{
	int	i;
	int	amount;

	i = 0;
	while (array[i] != min)
		i++;
	amount = count_elements(array);
	if (amount - i < i)
		count->reverse_rotate_a = amount - i;
	else
		count->rotate_a = i;
}

t_move_count	push_cost_b(long *stack_a, long *stack_b, int i, t_data *data)
{
	t_move_count	count;

	count = (t_move_count){};
	if (data->amount_of_elements_b - i < i)
		count.reverse_rotate_b = data->amount_of_elements_b - i;
	else
		count.rotate_b = i;
	if (stack_b[i] > data->max_a)
		array_cost_max_b(stack_a, &count, data->min_a);
	else if (stack_b[i] < data->min_a)
		array_cost_min(stack_a, &count, data->min_a);
	else
		array_cost_b(stack_b[i], stack_a, &count, data->min_a);
	final_calculations(&count);
	count.total = count.rotate_a + count.rotate_b + count.rotate_both
		+ count.reverse_rotate_a + count.reverse_rotate_b
		+ count.reverse_rotate_both;
	return (count);
}

int	find_the_number_min(long number, long *array, long min)
{
	int	i;

	i = 0;
	while (array[i] != min)
	{
		if (number < array[i])
			break ;
		i++;
	}
	return (i);
}

void	array_cost_b(long number, long *array, t_move_count *count, long min)
{
	int	i;
	int	lever;
	int	amount;

	i = 0;
	lever = 0;
	while (array[i] != min)
		i++;
	while (array[i] < 2147483648)
	{
		if (number < array[i])
		{
			lever = 1;
			break ;
		}
		i++;
	}
	if (lever == 0)
		i = find_the_number_min(number, array, min);
	amount = count_elements(array);
	if (amount - i < i)
		count->reverse_rotate_a = amount - i;
	else
		count->rotate_a = i;
}

void	push_cheapest_b(long **stack_a, long **stack_b, t_data *data)
{
	int				i;
	t_move_count	cheapest;
	t_move_count	tmp;

	i = 1;
	cheapest = push_cost_b(*stack_a, *stack_b, 0, data);
	while (i < data->amount_of_elements_b)
	{
		tmp = push_cost_b(*stack_a, *stack_b, i, data);
		if (tmp.total < cheapest.total)
			cheapest = tmp;
		i++;
	}
	use_rotate(cheapest, stack_a, stack_b);
	use_rev_rotate(cheapest, stack_a, stack_b);
	if (*stack_b[0] > data->max_a)
		data->max_a = *stack_b[0];
	if (*stack_b[0] < data->min_a)
		data->min_a = *stack_b[0];
	push_into_a(*stack_a, *stack_b);
}

void	push_back(long *stack_a, long *stack_b, t_data *data)
{
	data->max_a = stack_a[2];
	data->min_a = stack_a[0];
	while (data->amount_of_elements_b > 0)
	{
		push_cheapest_b(&stack_a, &stack_b, data);
		data->amount_of_elements_a++;
		data->amount_of_elements_b--;
	}
}