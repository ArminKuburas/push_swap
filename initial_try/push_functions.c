/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:17:08 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/17 05:17:17 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
