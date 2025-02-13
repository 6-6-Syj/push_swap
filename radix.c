/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-12 19:11:22 by jmagand           #+#    #+#             */
/*   Updated: 2025-02-12 19:11:22 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_size(t_stack *a)
{
	t_stack	*tmp;
	int		total_nodes;

	if (!a)
		return (0);
	tmp = a;
	total_nodes = 1;
	while (tmp->next != a)
	{
		total_nodes++;
		tmp = tmp->next;
	}
	return (total_nodes);
}

static int	max_bits(t_stack *a)
{
	int		max_value;
	int		bits;
	t_stack	*tmp;

	max_value = a->value;
	bits = 0;
	tmp = a;
	// Trouver la valeur maximale dans la pile
	while (tmp->next != a)
	{
		if (tmp->value > max_value)
			max_value = tmp->value;
		tmp = tmp->next;
	}
	// Calculer le nombre de bits nécessaires pour représenter max_value
	while ((max_value >> bits) != 0)
		bits++;
	return (bits);
}

static int	is_sort(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*start;

	if (!a || !(*a))
		return (0);
	tmp = *a;
	start = *a;
	while (tmp->next != start)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int algo_radix(t_stack **a, t_stack **b)
{
    int mask;
    int size_a;
    int i;
    int bit_count;
    int bit;

    if (!a || !(*a))
        return (0);
    size_a = stack_size(*a);
    bit_count = max_bits(*a);
    mask = 1;
    bit = 1;
    while (bit <= bit_count)
    {
        i = 0;
        while (i < size_a)
        {
            if (!(*a))
                break;
            if (!((*a)->value & mask))
                push_b(a, b);
            else
                rotate_a(a);
            i++;
        }
        while (*b)
            push_a(a, b);
        mask <<= 1;
        bit++;
		if (is_sort(a))
			return (1);
    }
    return (0);
}
