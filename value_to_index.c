/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_to_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-07 20:32:50 by jmagand           #+#    #+#             */
/*   Updated: 2025-02-07 20:32:50 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*sort_arr(int *arr, size_t len)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

static int	*get_index(int *arr, int *sorted_arr, size_t len)
{
	int		*index;
	size_t	i;
	size_t	j;

	index = malloc(sizeof(int) * len);
	if (!index)
		return (NULL);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (arr[i] == sorted_arr[j])
			{
				index[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (index);
}

int	*modify_value(int *arr, size_t len)
{
	int		*tmp_arr;
	int		*sorted_tmp_arr;
	int		*index;
	size_t	i;

	i = 0;
	tmp_arr = malloc(sizeof(int) * len);
	if (!tmp_arr)
		return (NULL);
	while (i < len)
	{
		tmp_arr[i] = arr[i];
		i++;
	}
	sorted_tmp_arr = sort_arr(tmp_arr, len);
	index = get_index(arr, sorted_tmp_arr, len);
	free(tmp_arr);
	if (!index)
		return (NULL);
	return (index);
}
