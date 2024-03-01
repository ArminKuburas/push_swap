/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 03:30:12 by akuburas          #+#    #+#             */
/*   Updated: 2024/03/01 14:01:20 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	stack_allocator(long **stack_a, long **stack_b, int amount_of_args)
{
	int	i;

	*stack_a = (long *)malloc(sizeof(long) * (amount_of_args + 1));
	if (!(*stack_a))
		return (MALLOC_ERROR);
	*stack_b = (long *)malloc(sizeof(long) * (amount_of_args + 1));
	if (!*stack_b)
	{
		free(*stack_a);
		return (MALLOC_ERROR);
	}
	i = 0;
	while (i < amount_of_args + 1)
	{
		(*stack_b)[i] = 2147483648;
		i++;
	}
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
	if (ft_strlen(str) == (size_t)i)
		return (1);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_arguments(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_strlen(args[i]) > 11)
			return (-1);
		if (ft_isinteger(args[i]) == 1)
			return (-1);
		i++;
	}
	if (i < 1)
		return (-1);
	return (i);
}
