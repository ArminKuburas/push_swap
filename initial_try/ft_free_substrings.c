/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_substrings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:34:00 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/14 03:45:29 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_free_substrings(char ***arr_str)
{
	int	i;

	i = 0;
	while ((*arr_str)[i] != NULL)
	{
		free((*arr_str)[i]);
		(*arr_str)[i] = NULL;
		i++;
	}
	if (*arr_str != NULL)
	{
		free(*arr_str);
		*arr_str = NULL;
	}
}
