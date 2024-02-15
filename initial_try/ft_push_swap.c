/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:18:31 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/15 05:18:00 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>
int	main(int argc, char **argv)
{
	long	*stack_a;
	long	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit_handler(WRONG_AMOUNT_OF_ARGUMENTS);
	initialize_stacks(&stack_a, &stack_b, argc, argv);
	int i = 0;
	while (i < argc - 1)
	{
		printf("%ld\n", stack_a[i]);
		i++;
	}
	printf("%ld\n", stack_a[i]);
	free(stack_a);
	free(stack_b);
	return (0);
}
