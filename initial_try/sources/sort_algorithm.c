/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:09:03 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/21 09:16:26 by akuburas         ###   ########.fr       */
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

int	find_the_number(long *stack_b, int value)
{
	int		i;

	i = 0;
	while (stack_b[i] != value)
		i++;
	return (i);
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
		i = find_the_number(array, max);
	amount = count_elements(array);
	if (amount - i < i)
		count->reverse_rotate_b = amount - i;
	else
		count->rotate_b = i;
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
	ft_printf("This is i = %d\n", i);
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
	ft_printf("Inside array_cost_b. After the while loop that tries to find the min value inside stack a. This is i = %d\n", i);
	ft_printf("This is array[i] = %d\n", array[i]);
	ft_printf("This is the value inside stack a that i is pointing to = %d\n", array[i]);
	while (array[i] < 2147483648)
	{
		if (number < array[i])
		{
			lever = 1;
			break ;
		}
		i++;
	}
	ft_printf(" WE are inside array_cost_b This is i = %d\n", i);
	if (lever == 0)
		i = find_the_number_min(number, array, min);
	amount = count_elements(array);
	if (amount - i < i)
		count->reverse_rotate_a = amount - i;
	else
		count->rotate_a = i;
}

void	final_calculations(t_move_count *count)
{
	if (count->rotate_a > count->rotate_b)
	{
		count->rotate_both = count->rotate_b;
		count->rotate_b = 0;
		count->rotate_a -= count->rotate_b;
	}
	else if (count->rotate_a < count->rotate_b)
	{
		count->rotate_both = count->rotate_a;
		count->rotate_a = 0;
		count->rotate_b -= count->rotate_a;
	}
	if (count->reverse_rotate_a > count->reverse_rotate_b)
	{
		count->reverse_rotate_both = count->reverse_rotate_b;
		count->reverse_rotate_b = 0;
		count->reverse_rotate_a -= count->reverse_rotate_b;
	}
	else if (count->reverse_rotate_a < count->reverse_rotate_b)
	{
		count->reverse_rotate_both = count->reverse_rotate_a;
		count->reverse_rotate_a = 0;
		count->reverse_rotate_b -= count->reverse_rotate_a;
	}
}

void	array_cost_max(long *array, t_move_count *count, long max)
{
	int	i;
	int	amount;

	i = 0;
	while (array[i] != max)
		i++;
	amount = count_elements(array);
	if (amount - i < i)
		count->rotate_b = amount - i;
	else
		count->reverse_rotate_b = i;
}

void	array_cost_max_b(long *array, t_move_count *count, long max)
{
	int	i;
	int	amount;

	i = 0;
	while (array[i] != max)
		i++;
	amount = count_elements(array);
	if (amount - i < i)
		count->rotate_a = amount - i;
	else
		count->reverse_rotate_a = i;
}

t_move_count	push_cost(long *stack_a, long *stack_b, int i, t_data *data)
{
	t_move_count	count;

	count = (t_move_count){};
	if (data->amount_of_elements_a - i < i)
		count.reverse_rotate_a = data->amount_of_elements_a - i;
	else
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
	ft_printf("This is stack_a[i] = %d\n", stack_a[i]);
	if (stack_b[i] > data->max_a)
		array_cost_max_b(stack_a, &count, data->max_a);
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

void	use_rotate(t_move_count cheapest, long **stack_a, long **stack_b)
{
	while (cheapest.rotate_a > 0)
	{
		rotate_a(*stack_a);
		cheapest.rotate_a--;
	}
	while (cheapest.rotate_b > 0)
	{
		rotate_b(*stack_b);
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
		reverse_rotate_a(*stack_a);
		cheapest.reverse_rotate_a--;
	}
	while (cheapest.reverse_rotate_b > 0)
	{
		reverse_rotate_b(*stack_b);
		cheapest.reverse_rotate_b--;
	}
	while (cheapest.reverse_rotate_both > 0)
	{
		reverse_rotate_both(*stack_a, *stack_b);
		cheapest.reverse_rotate_both--;
	}
}

void	push_cheapest(long **stack_a, long **stack_b, t_data *data)
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
	ft_printf("We are inside push_cheapest\n");
	ft_printf("This is stack_a[0] = %d\n", *stack_a[0]);
	ft_printf("This is stack_b[0] = %d\n", *stack_b[0]);
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
	ft_printf("We are inside push_cheapest_b\n");
	ft_printf("This is min_a = %d\n", data->min_a);
	ft_printf("This is stack_a[0] = %d\n", *stack_a[0]);
	ft_printf("This is stack_b[0] = %d\n", *stack_b[0]);
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

void	check_order(long *stack_a, long min_value, int amount)
{
	int	i;
	int	rotate_amount;

	i = 0;
	ft_printf("We are inside check_order\n");
	ft_printf("This is amount = %d\n", amount);
	ft_printf("This is min_value = %d\n", min_value);
	while (stack_a[i] != min_value)
	{
		i++;
	}
	ft_printf("This is i = %d\n", i);
	if (amount - i < i)
	{
		rotate_amount = amount - i;
		while (rotate_amount > 0)
		{
			reverse_rotate_a(stack_a);
			rotate_amount--;
		}
	}
	else
	{
		while (i > 0)
		{
			rotate_a(stack_a);
			i--;
		}
	}
}

void	print_stacks(long *stack_a, long *stack_b)
{
	int	i;

	i = -1;
	ft_printf("we are inside print_stacks\n");
	while (stack_a[i++] < 2147483648)
		ft_printf("This is stack_a[%d] = %d\n", i, stack_a[i]);
	i = -1;
	while (stack_b[i++] < 2147483648)
		ft_printf("This is stack_b[%d] = %d\n", i, stack_b[i]);
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
		print_stacks(*stack_a, *stack_b);
		ft_printf("Before initial_push\n");
		initial_push(*stack_a, *stack_b, &data);
		ft_printf("After initial_push\n");
		print_stacks(*stack_a, *stack_b);
		initial_sort(stack_a, stack_b, &data);
		ft_printf("After initial_sort\n");
		print_stacks(*stack_a, *stack_b);
		sort_three(stack_a);
		data.min_a = (*stack_a)[0];
		data.max_a = (*stack_a)[2];
		ft_printf("After sort_three\n");
		print_stacks(*stack_a, *stack_b);
		push_back(*stack_a, *stack_b, &data);
		ft_printf("After push_back\n");
		print_stacks(*stack_a, *stack_b);
		check_order(*stack_a, data.min_a, data.amount_of_elements_a);
		ft_printf("After check_order\n");
	}
}
