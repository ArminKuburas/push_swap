/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join2DArrays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 02:47:53 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/15 03:04:33 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	help_strdup(char **arr1, char **arr2, char **new)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (arr1 != NULL)
	{
		while (arr1[j] != NULL)
		{
			new[j] = ft_strdup(arr1[j]);
			if (!new[j])
				return (1);
			j++;
		}
	}
	while (arr2[i] != NULL)
	{
		new[i + j] = ft_strdup(arr2[i]);
		if (!new[i + j])
			return (1);
		i++;
	}
	new[i + j] = NULL;
	return (0);
}

char	**join2darrays(char **arr1, char **arr2)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (arr2[i] != NULL)
		i++;
	if (arr1 != NULL)
		while (arr1[j] != NULL)
			j++;
	new = (char **)malloc(sizeof(char *) * (i + j + 1));
	if (!new)
		return (NULL);
	if (help_strdup(arr1, arr2, new) == 1)
		return (NULL);
	return (new);
}
