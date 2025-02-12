/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 18:53:04 by jmagand           #+#    #+#             */
/*   Updated: 2025-02-11 18:53:04 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	algo_3(t_stack **a)
{
	t_stack	*next;
	t_stack	*end;

	next = (*a)->next;
	end = (*a)->prev;
	if ((*a)->value < end->value && next->value < end->value) /* 2 1 3 */
		swap_a(a);
	else if ((*a)->value > next->value && next->value > end->value) /* 3 2 1 */
	{
		rotate_a(a);
		swap_a(a);
	}
	else if ((*a)->value < next->value && (*a)->value < end->value) /* 1 3 2 */
	{
		reverse_rotate_a(a);
		swap_a(a);
	}
	else if ((*a)->value < next->value && (*a)->value > end->value) /* 2 3 1 */
		reverse_rotate_a(a);
	else if ((*a)->value > next->value && next->value < end->value) /* 3 1 2 */
		rotate_a(a);
	if(is_sort(a))
		return (1);
	return (0);
}

static int find_min(t_stack *a)
{
	int     min;
	t_stack *current;

	if (!a)
		return (0);
	min = a->value;
	current = a->next;
	while (current != a)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

static size_t get_position(t_stack **a, int value)
{
	size_t  pos;
	t_stack *current;

	pos = 0;
	current = *a;
	while (current->value != value)
	{
		current = current->next;
		pos++;
	}
	return (pos);
}

int algo_5(t_stack **a, t_stack **b, size_t len)
{
    size_t  i;
    int     min;

	if (!a || !*a)
		return (0);
	i = 0;
	while (i < len - 1)
	{
		min = find_min(*a);
		while ((*a)->value != min)
		{
			if (get_position(a, min) <= len / 2)
				rotate_a(a);
			else
				reverse_rotate_a(a);
		}
		push_b(a, b);
		i++;
	}
	while (*b)
		push_a(a, b);
	if (is_sort(a))
		return (1);
	return (0);
}

// void	algo_radix(t_stack **a, t_stack **b)
// {

// }
