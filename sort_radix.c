/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-12 19:11:22 by jmagand           #+#    #+#             */
/*   Updated: 2025-02-12 19:11:22 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_biggest(t_stack *a)
{
	int		big;
	t_stack	*tmp;

	if (!a)
		return (0);
	big = INT_MIN;
	tmp = a;
	while (tmp->next != a)
	{
		if (tmp->value > big)
			big = tmp->value;
		tmp = tmp->next;
	}
	return (big);
}

static int	find_bits(int biggest_nb)
{
	int	max_bits;

	max_bits = 0;
	while ((biggest_nb >> max_bits) > 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	biggest_nbr;
	int	max_bits;
	int	i;
	int	j;

	biggest_nbr = find_biggest(*a);
	max_bits = find_bits(biggest_nbr);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j <= biggest_nbr)
		{
			if (((*a)->value >> i) & 1)
				rotate_a(a);
			else
				push_b(a, b);
			j++;
		}
		while (*b)
			push_a(a, b);
		i++;
	}
}

void free_all(t_stack **a, t_stack **b, int *index_arr, int *args)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (index_arr)
		free(index_arr);
	if (args)
		free(args);
}

int	choose_algo(t_stack *a, t_stack *b, size_t len, int *args)
{
	int		*index_arr;
	size_t	i;

	i = 0;
	index_arr = NULL;
	if (len <= 5)
	{
		sort_three_or_five(&a, &b, args, len);
		free_all(&a, &b, index_arr, args);
		return (1);
	}
	else if (!is_sort(&a))
	{
		index_arr = modify_value(args, len);
		while (i < len)
		{
			add_node_list(&a, args[i]);
			i++;
		}
		radix_sort(&a, &b);
	}
	if (index_arr)
		free_all(&a, &b, index_arr, args);
	return (0);
}
