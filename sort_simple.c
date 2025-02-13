/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 18:53:04 by jmagand           #+#    #+#             */
/*   Updated: 2025-02-11 18:53:04 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_stack **a)
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

static int	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		swap_a(a);
	else if (first > second && second > third)
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
	else if (first > second && second < third && first > third)
		rotate_a(a);
	else if (first < second && second > third && first < third)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_a(a);
	return (1);
}

static int	sort_five(t_stack **a, t_stack **b, size_t len)
{
	while (len != 0)
	{
		if ((*a)->value == 0 || (*a)->value == 1)
			push_b(a, b);
		else
			rotate_a(a);
		len--;
	}
	sort_three(a);
	push_a(a, b);
	push_a(a, b);
	if ((*a)->value > (*a)->next->value)
		swap_a(a);
	if (is_sort(a))
		return (1);
	return (0);
}

static void	sort_three_or_five(t_stack **a, t_stack **b, int *args, size_t len)
{
	size_t	i;

	i = 0;
	if (len <= 5)
	{
		while (i < len)
		{
			add_node_list(a, args[i]);
			i++;
		}
	}
	if (!is_sort(a) && len <= 3)
		sort_three(a);
	else if (!is_sort(a) && len <= 5)
		sort_five(a, b, len);
}

int	choose_algo(t_stack *a, t_stack *b, size_t len, int *args)
{
	int		*index_arr;
	size_t	i;

	i = 0;
	if (len <= 5)
	{
		sort_three_or_five(&a, &b, args, len);
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
	else
	{
		free(a);
		free(b);
	}
	return (0);
}
