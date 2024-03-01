/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 03:30:31 by akuburas          #+#    #+#             */
/*   Updated: 2024/03/01 14:16:38 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	exit_handler(int error)
{
	if (error == WRONG_AMOUNT_OF_ARGUMENTS)
		ft_putstr_fd("Error\n", 2);
	else if (error == MALLOC_ERROR)
		ft_putstr_fd("Error\n", 2);
	else if (error == WRONG_ARGUMENTS)
		ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	check_if_empty(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "") == 0)
			return (1);
		i++;
	}
	return (0);
}
