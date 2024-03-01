/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 04:47:12 by akuburas          #+#    #+#             */
/*   Updated: 2024/03/01 12:41:22 by akuburas         ###   ########.fr       */
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

void	swap_both(long *stack_a, long *stack_b)
{
	ft_putstr_fd("ss\n", 1);
	swap_a(stack_a);
	swap_b(stack_b);
}
