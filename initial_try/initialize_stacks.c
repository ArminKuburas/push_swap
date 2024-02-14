/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 03:30:12 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/14 07:51:14 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	stack_allocator(long *stack_a, int argc)
{
	stack_a = (long *)malloc(sizeof(long) * (argc - 1));
	if (!stack_a)
		exit_handler(MALLOC_ERROR);
}

void	argument_creator(int argc, char **argv, char **args)
{
	int		i;
	char	**temp_args;

	i = 1;
	while (i < argc)
	{
		temp_args = ft_split(argv[i], ' ');
		ft_printf("inside argument_creator after ft_split\n");
		if (!temp_args)
		{
			exit_handler(MALLOC_ERROR);
			if (i > 1)
				ft_free_substrings(&args);
		}
		args = join2darrays(temp_args, args);
		ft_printf("inside argument_creator after join2darrays\n");
		ft_free_substrings(&temp_args);
		if (!args)
			exit_handler(MALLOC_ERROR);
		i++;
	}
}

void	turn_into_stack(long *stack_a, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		stack_a[i] = ft_atoi(args[i]);
		ft_printf("stack_a[i]: %ld\n", stack_a[i]);
		if (stack_a[i] > INT_MAX || stack_a[i] < INT_MIN)
		{
			ft_free_substrings(&args);
			free(stack_a);
			exit_handler(WRONG_ARGUMENTS);
		}
		i++;
	}
	ft_free_substrings(&args);
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

void	check_arguments(char **args)
{
	int	i;

	i = 0;
	ft_printf("args[0]: %s\n", args[0]);
	ft_printf("inside check_arguments\n");
	while (args[i])
	{
		ft_printf("args[i]: %s\n", args[i]);
		if (ft_strlen(args[i]) > 11)
		{
			ft_free_substrings(&args);
			exit_handler(WRONG_ARGUMENTS);
		}
		if (!ft_isinteger(args[i]))
		{
			ft_free_substrings(&args);
			exit_handler(WRONG_ARGUMENTS);
		}
		i++;
	}
}

void	initialize_stacks(long *stack_a, long *stack_b, int argc, char **argv)
{
	char	**args;

	args = NULL;
	ft_printf("Inside initialize_stacks\n");
	stack_allocator(stack_a, argc);
	ft_printf("Inside initialize_stacks after stack_allocator\n");
	argument_creator(argc, argv, args);
	ft_printf("Inside initialize_stacks after argument_creator\n");
	check_arguments(args);
	ft_printf("Inside initialize_stacks after check_arguments\n");
	turn_into_stack(stack_a, args);
	ft_printf("Inside initialize_stacks after turn_into_stack\n");
	stack_b = (long *)malloc(sizeof(long) * (argc - 1));
	if (!stack_b)
	{
		free(stack_a);
		exit_handler(MALLOC_ERROR);
	}
}
