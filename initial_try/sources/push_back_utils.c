/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:57:03 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/21 12:57:16 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	find_the_number_min(long number, long *array, long min)
{
	int	i;

	i = 0;
	while (array[i] != min)
	{
		if (number < array[i])
			break ;
		i++;
	}
	return (i);
}
