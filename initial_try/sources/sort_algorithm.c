/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:09:03 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/21 23:25:23 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	initial_push(long *stack_a, long *stack_b, t_data *data)
{
	int		i;

	i = 0;
	while (data->amount_of_elements_a > 3 && i < 2)
	{
		push_into_b(stack_a, stack_b);
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

void	sort_three(long **stack_a)
{
	if ((*stack_a)[0] > (*stack_a)[1] && (*stack_a)[1] < (*stack_a)[2]
		&& (*stack_a)[0] < (*stack_a)[2])
		swap_a(*stack_a);
	else if ((*stack_a)[0] > (*stack_a)[1] && (*stack_a)[0] > (*stack_a)[2]
		&& (*stack_a)[1] < (*stack_a)[2])
		rotate_a(*stack_a, 0);
	else if ((*stack_a)[0] < (*stack_a)[1] && (*stack_a)[0] > (*stack_a)[2] &&
		(*stack_a)[1] > (*stack_a)[2])
		reverse_rotate_a(*stack_a, 0);
	else if ((*stack_a)[0] > (*stack_a)[1] && (*stack_a)[1] > (*stack_a)[2])
	{
		swap_a(*stack_a);
		reverse_rotate_a(*stack_a, 0);
	}
	else if ((*stack_a)[0] < (*stack_a)[1] && (*stack_a)[1] > (*stack_a)[2])
	{
		swap_a(*stack_a);
		rotate_a(*stack_a, 0);
	}
}

void	check_order(long *stack_a, long min_value, int amount)
{
	int	i;
	int	rotate_amount;

	i = 0;
	while (stack_a[i] != min_value)
	{
		i++;
	}
	if (amount - i < i)
	{
		rotate_amount = amount - i;
		while (rotate_amount > 0)
		{
			reverse_rotate_a(stack_a, 0);
			rotate_amount--;
		}
	}
	else
	{
		while (i > 0)
		{
			rotate_a(stack_a, 0);
			i--;
		}
	}
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

void	print_stack(long *stack_a, long *stack_b, t_data *data)
{
	int	i;

	i = 0;
	ft_putstr_fd("Stack A: ", 1);
	while (i < data->amount_of_elements_a)
	{
		ft_putnbr_fd(stack_a[i], 1);
		ft_putstr_fd(" ", 1);
		i++;
	}
	ft_putstr_fd("\n", 1);
	i = 0;
	ft_putstr_fd("Stack B: ", 1);
	while (i < data->amount_of_elements_b)
	{
		ft_putnbr_fd(stack_b[i], 1);
		ft_putstr_fd(" ", 1);
		i++;
	}
	ft_putstr_fd("\n", 1);
}

void	sort_stack(long **stack_a, long **stack_b)
{
	t_data	data;

	data = (t_data){};
	data.amount_of_elements = count_elements(*stack_a);
	data.amount_of_elements_a = data.amount_of_elements;
	if (data.amount_of_elements <= 3)
		sort_small_stack(stack_a, data.amount_of_elements);
	else
	{
		initial_push(*stack_a, *stack_b, &data);
		initial_sort(stack_a, stack_b, &data);
		sort_three(stack_a);
		data.min_a = (*stack_a)[0];
		data.max_a = (*stack_a)[2];
		push_back(*stack_a, *stack_b, &data);
		check_order(*stack_a, data.min_a, data.amount_of_elements_a);
	}
}
