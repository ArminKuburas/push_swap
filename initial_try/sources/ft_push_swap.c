/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:18:31 by akuburas          #+#    #+#             */
/*   Updated: 2024/03/01 14:13:43 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	check_duplicate(long *stack_a)
{
	int	i;
	int	j;

	i = 0;
	while (stack_a[i] < 2147483648)
	{
		j = i + 1;
		while (stack_a[j] < 2147483648)
		{
			if (stack_a[i] == stack_a[j])
				return (WRONG_ARGUMENTS);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_if_already_sorted(long *stack_a)
{
	int	i;

	i = 0;
	while (stack_a[i] != 2147483648)
	{
		if (stack_a[i] > stack_a[i + 1])
			return (1);
		i++;
	}
	return (0);
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

void	init_stacks(long **stack_a, long **stack_b, int argc, char **argv)
{
	char	**args;
	int		i;

	args = NULL;
	if (argument_creator(argc, argv, &args) == MALLOC_ERROR)
		exit_handler(MALLOC_ERROR);
	i = check_arguments(args);
	if (i == -1)
	{
		ft_free_substrings(&args);
		exit_handler(WRONG_ARGUMENTS);
	}
	if (stack_allocator(stack_a, stack_b, i) == MALLOC_ERROR)
	{
		ft_free_substrings(&args);
		exit_handler(MALLOC_ERROR);
	}
	i = turn_into_stack(stack_a, args);
	ft_free_substrings(&args);
	if (i == WRONG_ARGUMENTS)
	{
		free(*stack_b);
		exit_handler(WRONG_ARGUMENTS);
	}
}

int	main(int argc, char **argv)
{
	long	*stack_a;
	long	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (check_if_empty(argc, argv) == 1)
		exit_handler(WRONG_ARGUMENTS);
	init_stacks(&stack_a, &stack_b, argc, argv);
	if (check_duplicate(stack_a) == WRONG_ARGUMENTS)
	{
		free(stack_a);
		free(stack_b);
		exit_handler(WRONG_ARGUMENTS);
	}
	if (check_if_already_sorted(stack_a) == 1)
		sort_stack(&stack_a, &stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
