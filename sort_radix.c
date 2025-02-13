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
