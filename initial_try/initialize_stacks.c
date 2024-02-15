/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 03:30:12 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/15 06:49:17 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	stack_allocator(long **stack_a, int amount_of_arguments)
{
	ft_printf("inside stack_allocator\n");
	ft_printf("amount_of_arguments = %d\n", amount_of_arguments);
	*stack_a = (long *)malloc(sizeof(long) * (amount_of_arguments + 1));
	if (!(*stack_a))
		exit_handler(MALLOC_ERROR);
}

void	argument_creator(int argc, char **argv, char ***args)
{
	int		i;
	char	**temp_args;

	i = 1;
	while (i < argc)
	{
		temp_args = ft_split(argv[i], ' ');
		if (!temp_args)
		{
			exit_handler(MALLOC_ERROR);
		}
		*args = join2darrays(*args, *args, temp_args);
		ft_free_substrings(&temp_args);
		ft_printf("after free\n");
		if (!args)
			exit_handler(MALLOC_ERROR);
		i++;
	}
}

void	turn_into_stack(long **stack_a, char **args)
{
	int	i;

	i = 0;
	ft_printf("inside turn_into_stack\n");
	while (args[i])
	{
		(*stack_a)[i] = ft_atoi(args[i]);
		ft_printf("(*stack_a)[%d] = %d\n", i, (*stack_a)[i]);
		if ((*stack_a)[i] > INT_MAX || (*stack_a)[i] < INT_MIN)
		{
			ft_free_substrings(&args);
			free(*stack_a);
			exit_handler(WRONG_ARGUMENTS);
		}
		i++;
	}
	(*stack_a)[i] = 2147483648;
	ft_printf("(*stack_a)[%d] = %u\n", i, (*stack_a)[i]);
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
		{
			ft_free_substrings(&args);
			return (-1);
		}
		if (!ft_isinteger(args[i]))
		{
			ft_free_substrings(&args);
			return (-1);
		}
		i++;
	}
	ft_printf("inside check_arguments i = %d\n", i);
	return (i);
}

void	initialize_stacks(long **stack_a, long **stack_b, int argc, char **argv)
{
	char	**args;
	int		i;

	args = NULL;
	argument_creator(argc, argv, &args);
	i = 0;
	ft_printf("after argument_creator\n");
	while (args[i])
	{
		ft_printf("%s\n", args[i]);
		i++;
	}
	ft_printf("after while args[i] = %s\n", args[i]);
	i = check_arguments(args);
	if (i == -1)
		exit(1);
	stack_allocator(stack_a, i);
	turn_into_stack(stack_a, args);
	*stack_b = (long *)malloc(sizeof(long) * (argc - 1));
	if (!*stack_b)
	{
		free(stack_a);
		exit_handler(MALLOC_ERROR);
	}
	ft_free_substrings(&args);
	int j = 0;
	while (j < i)
	{
		ft_printf("stack_a[%d] = %d\n", j, (*stack_a)[j]);
		j++;
	}
	ft_printf("stack_a[%d] = %u\n", j, (*stack_a)[j]);
}
