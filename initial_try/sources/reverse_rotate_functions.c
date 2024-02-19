/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:34:06 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/18 07:45:20 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
	i--;
	tmp = stack_a[i];
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
	i--;
	tmp = stack_b[i];
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
