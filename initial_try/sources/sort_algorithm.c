/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:09:03 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/19 22:06:26 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	initial_push(long *stack_a, long *stack_b, t_data *data)
{
	int		i;

	i = 0;
	while (data->amount_of_elements_a > 3 && i < 2)
	{
		push_b(stack_a, stack_b);
		data->amount_of_elements_a--;
		data->amount_of_elements_b++;
		i++;
	}
	if (data->amount_of_elements_b == 2)
	{
		if (stack_b[0] < stack_b[1])
		{
			data->max_b = stack_b[1];
			data->min_b = stack_b[0];
		}
		else
		{
			data->max_b = stack_b[0];
			data->min_b = stack_b[1];
		}
	}
}

/*
1-1-2-2-3-3
2-3-3-1-2-1
3-2-1-3-1-2
*/
void	sort_three(long **stack_a)
{
	if ((*stack_a)[0] > (*stack_a)[1] && (*stack_a)[1] < (*stack_a)[2]
		&& (*stack_a)[0] < (*stack_a)[2])
		swap_a(*stack_a);
	else if ((*stack_a)[0] > (*stack_a)[1] && (*stack_a)[0] > (*stack_a)[2]
		&& (*stack_a)[1] < (*stack_a)[2])
		rotate_a(*stack_a);
	else if ((*stack_a)[0] < (*stack_a)[1] && (*stack_a)[0] > (*stack_a)[2] &&
		(*stack_a)[1] > (*stack_a)[2])
		reverse_rotate_a(*stack_a);
	else if ((*stack_a)[0] > (*stack_a)[1] && (*stack_a)[1] > (*stack_a)[2])
	{
		swap_a(*stack_a);
		reverse_rotate_a(*stack_a);
	}
	else if ((*stack_a)[0] < (*stack_a)[1] && (*stack_a)[1] > (*stack_a)[2])
	{
		swap_a(*stack_a);
		rotate_a(*stack_a);
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

void	b_cost(long number, long *stack_b, t_move_count *count, int max_b)
{
	int		i;
	int		lever;

	i = 0;
	lever = 0;
	while (stack_b[i] != max_b)
		i++;
	while (stack_b[i] < 2147483648)
	{
		if (number > stack_b[i])
		{
			lever = 1;
			break ;
		}
		i++;
	}
	if (lever == 0)
	{
		i = function_name_here(stack_b, max_b);
		while (stack_b[i] != max_b)
		{
			if (number > stack_b[i])
				break ;
			i++;
		}
	}
}

t_move_count	push_cost(long *stack_a, long *stack_b, int i, t_data *data)
{
	t_move_count	count;

	count = (t_move_count){};
	if (amount - i + 1 < i)
		count.reverse_rotate_a = amount - i + 1;
	else
		count.rotate_a = i;
	b_cost(stack_a[i], stack_b, &count, data->max_b);
	return (count);
}

void	push_cheapest(long **stack_a, long **stack_b, t_data *data)
{
	int				i;
	t_move_count	cheapest;
	t_move_count	tmp;

	i = 0;
	cheapest = push_cost(*stack_a, *stack_b, i, data);
}

void	initial_sort(long **stack_a, long **stack_b, t_data *data)
{
	while (data->amount_of_elements_a > 3)
	{
		push_cheapest(stack_a, stack_b, data);
		data->amount_of_elements_a--;
	}
}

void	sort_stack(long **stack_a, long **stack_b)
{
	t_data	data;

	data = (t_data){};
	data.amount_of_elements = count_elements(*stack_a);
	data.amount_of_elements_a = data.amount_of_elements;
	if (*stack_b)
		data.amount_of_elements_b = count_elements(*stack_b);
	if (data.amount_of_elements <= 3)
		sort_small_stack(stack_a, data.amount_of_elements);
	else
	{
		ft_printf("This hasn't been implemented yet\n");
	/*	initial_push(stack_a, stack_b, &data);
		initial_sort(stack_a, stack_b, &data);
		sort_three(stack_a);
		check_order(stack_a); */
	}
}
