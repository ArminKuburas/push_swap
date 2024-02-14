/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join2DArrays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 02:47:53 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/14 07:45:37 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	help_strdup(char **arr1, char **arr2, char **new)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr1[i])
	{
		new[i] = ft_strdup(arr1[i]);
		if (!new[i])
			return (1);
		i++;
	}
	if (arr2 != NULL)
	{
		while (arr2[j])
		{
			new[i + j] = ft_strdup(arr2[j]);
			if (!new[i + j])
				return (1);
			j++;
		}
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
	ft_printf("inside join2darrays\n");
	while (arr1[i])
		i++;
	ft_printf("inside join2darrays after first while\n");
	if (arr2 != NULL)
		while (arr2[j])
			j++;
	ft_printf("i: %d, j: %d\n", i, j);
	new = (char **)malloc(sizeof(char *) * (i + j + 1));
	if (!new)
		return (NULL);
	ft_printf("inside join2darrays after malloc\n");
	if (help_strdup(arr1, arr2, new) == 1)
		return (NULL);
	ft_printf("inside join2darrays after help_strdup\n");
	return (new);
}
