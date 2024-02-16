/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 03:30:12 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/16 01:14:19 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_bmax(long *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = 2147483648;
		i++;
	}
}

int	stack_allocator(long **stack_a, long **stack_b, int amount_of_arguments)
{
	*stack_a = (long *)malloc(sizeof(long) * (amount_of_arguments + 1));
	if (!(*stack_a))
		return (MALLOC_ERROR);
	*stack_b = (long *)malloc(sizeof(long) * (amount_of_arguments + 1));
	if (!*stack_b)
	{
		free(*stack_a);
		return (MALLOC_ERROR);
	}
	ft_bmax(*stack_b, amount_of_arguments + 1);
	return (0);
}

int	argument_creator(int argc, char **argv, char ***args)
{
	int		i;
	char	**temp_args;

	i = 1;
	while (i < argc)
	{
		temp_args = ft_split(argv[i], ' ');
		if (!temp_args)
			return (MALLOC_ERROR);
		*args = join2darrays(*args, *args, temp_args);
		ft_free_substrings(&temp_args);
		if (!args)
			return (MALLOC_ERROR);
		i++;
	}
	return (0);
}

int	turn_into_stack(long **stack_a, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		(*stack_a)[i] = ft_atoi(args[i]);
		if ((*stack_a)[i] > INT_MAX || (*stack_a)[i] < INT_MIN)
		{
			free(*stack_a);
			return (WRONG_ARGUMENTS);
		}
		i++;
	}
	(*stack_a)[i] = 2147483648;
	return (0);
}

int	ft_isinteger(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_arguments(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_strlen(args[i]) > 11)
			return (-1);
		if (!ft_isinteger(args[i]))
			return (-1);
		i++;
	}
	return (i);
}

void	initialize_stacks(long **stack_a, long **stack_b, int argc, char **argv)
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
