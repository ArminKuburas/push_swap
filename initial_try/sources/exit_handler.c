/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 03:30:31 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/16 03:47:43 by akuburas         ###   ########.fr       */
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