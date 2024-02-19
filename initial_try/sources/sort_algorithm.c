/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:09:03 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/18 07:41:44 by akuburas         ###   ########.fr       */
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

int	count_elements(long *stack_a)
{
	int		i;

	i = 0;
	while (stack_a[i] < 2147483648)
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
		initiate_sort(stack_a, stack_b, &data);
		sort_three(stack_a);
		check_order(stack_a); */
	}
}
