/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:18:31 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/29 11:43:47 by akuburas         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	long	*stack_a;
	long	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
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
