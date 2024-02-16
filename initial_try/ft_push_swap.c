/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:18:31 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/16 01:53:51 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	long	*stack_a;
	long	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit_handler(WRONG_AMOUNT_OF_ARGUMENTS);
	initialize_stacks(&stack_a, &stack_b, argc, argv);
	 if (check_stack(stack_a) == WRONG_ARGUMENTS)
	int i = 0;
	while (i < argc)
	{
		ft_printf("argv[%d] %s\n", i, argv[i]);
		i++;
	}
	i = 0;
	while (stack_a[i] < 2147483648)
	{
		ft_printf("stack_a[%d] %d\n", i, stack_a[i]);
		i++;
	}
	ft_printf("stack_a[%d] %u\n", i, stack_a[i]);
	while (i >= 0)
	{
		ft_printf("stack_b[%d] %u\n", i, stack_b[i]);
		i--;
	}
	free(stack_a);
	free(stack_b);
	return (0);
}
