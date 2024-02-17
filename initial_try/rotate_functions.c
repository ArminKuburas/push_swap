/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 05:17:35 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/17 05:17:46 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
