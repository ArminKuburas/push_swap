/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:18:31 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/16 09:05:20 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	swap_a(long *stack_a)
{
	long	tmp;

	if (stack_a[0] == 2147483648 || stack_a[1] == 2147483648)
		return ;
	ft_putstr_fd("sa\n", 1);
	tmp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = tmp;
}

void	swap_b(long *stack_b)
{
	long	tmp;

	if (stack_b[0] == 2147483648 || stack_b[1] == 2147483648)
		return ;
	ft_putstr_fd("sb\n", 1);
	tmp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = tmp;
}

void	push_a(long *stack_a, long *stack_b)
{
	int		i;

	if (stack_b[0] == 2147483648)
		return ;
	ft_putstr_fd("pa\n", 1);
	i = 0;
	while (stack_a[i] < 2147483648)
		i++;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = stack_b[0];
	i = 0;
	while (stack_b[i] < 2147483648)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
}

void	push_b(long *stack_a, long *stack_b)
{
	int		i;

	if (stack_a[0] == 2147483648)
		return ;
	ft_putstr_fd("pb\n", 1);
	i = 0;
	while (stack_b[i] < 2147483648)
		i++;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = stack_a[0];
	i = 0;
	while (stack_a[i] < 2147483648)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
}

void	rotate_a(long *stack_a)
{
	long	tmp;
	int		i;

	if (stack_a[0] == 2147483648)
		return ;
	ft_putstr_fd("ra\n", 1);
	tmp = stack_a[0];
	i = 0;
	while (stack_a[i] < 2147483648)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i - 1] = tmp;
}

void	rotate_b(long *stack_b)
{
	long	tmp;
	int		i;

	if (stack_b[0] == 2147483648)
		return ;
	ft_putstr_fd("rb\n", 1);
	tmp = stack_b[0];
	i = 0;
	while (stack_b[i] < 2147483648)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[i - 1] = tmp;
}

void	rotate_both(long *stack_a, long *stack_b)
{
	ft_putstr_fd("rr\n", 1);
	rotate_a(stack_a);
	rotate_b(stack_b);
}

void	reverse_rotate_a(long *stack_a)
{
	long	tmp;
	int		i;

	if (stack_a[0] == 2147483648)
		return ;
	ft_putstr_fd("rra\n", 1);
	i = 0;
	while (stack_a[i] < 2147483648)
		i++;
	tmp = stack_a[i - 1];
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = tmp;
}

void	reverse_rotate_b(long *stack_b)
{
	long	tmp;
	int		i;

	if (stack_b[0] == 2147483648)
		return ;
	ft_putstr_fd("rrb\n", 1);
	i = 0;
	while (stack_b[i] < 2147483648)
		i++;
	tmp = stack_b[i - 1];
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = tmp;
}

void	reverse_rotate_both(long *stack_a, long *stack_b)
{
	ft_putstr_fd("rrr\n", 1);
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}

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

int	main(int argc, char **argv)
{
	long	*stack_a;
	long	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	initialize_stacks(&stack_a, &stack_b, argc, argv);
	/* swap_b(stack_b);
	swap_both(stack_a, stack_b);
	rotate_a(stack_a);
	rotate_b(stack_b);
	rotate_both(stack_a, stack_b);
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	reverse_rotate_both(stack_a, stack_b); */
	if (check_duplicate(stack_a) == WRONG_ARGUMENTS)
	{
		free(stack_a);
		free(stack_b);
		exit_handler(WRONG_ARGUMENTS);
	}
	ft_printf("stack_a[0] %d\n", stack_a[0]);
	ft_printf("stack_a[1] %d\n", stack_a[1]);
	swap_a(stack_a);
	ft_printf("stack_a[0] %d\n", stack_a[0]);
	ft_printf("stack_a[1] %d\n", stack_a[1]);
	push_b(stack_a, stack_b);
	ft_printf("stack_a[0] %d\n", stack_a[0]);
	ft_printf("stack_a[1] %u\n", stack_a[1]);
	ft_printf("stack_b[0] %d\n", stack_b[0]);
	push_a(stack_a, stack_b);
	ft_printf("stack_a[0] %d\n", stack_a[0]);
	ft_printf("stack_a[1] %d\n", stack_a[1]);
	ft_printf("stack_b[0] %u\n", stack_b[0]);
	free(stack_a);
	free(stack_b);
	return (0);
}
