/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 22:18:20 by jmagand           #+#    #+#             */
/*   Updated: 2025-02-04 22:18:20 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 	Prend le premier élément au sommet de b et le met sur a.
	Ne fait rien si b est vide. */

static void	push_to_a(t_stack **a, t_stack *tmp_b)
{
	if (!(*a))
	{
		*a = tmp_b;
		tmp_b->next = tmp_b;
		tmp_b->prev = tmp_b;
	}
	else
	{
		tmp_b->next = *a;
		tmp_b->prev = (*a)->prev;
		(*a)->prev->next = tmp_b;
		(*a)->prev = tmp_b;
		*a = tmp_b;
	}
}

static void	push_to_b(t_stack **b, t_stack *tmp_a)
{
	if (!(*b))
	{
		*b = tmp_a;
		tmp_a->next = tmp_a;
		tmp_a->prev = tmp_a;
	}
	else
	{
		tmp_a->next = *b;
		tmp_a->prev = (*b)->prev;
		(*b)->prev->next = tmp_a;
		(*b)->prev = tmp_a;
		*b = tmp_a;
	}
}

int		push_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;

	if (!(*b))
        return (0);
	tmp_b = *b;
	if ((*b)->next == *b)
		*b = NULL;
	else
	{
		*b = (*b)->next;
		(*b)->prev = tmp_b->prev;
		tmp_b->prev->next = *b;
	}
	push_to_a(a, tmp_b);
	return (1);
}

int		push_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;

	if (!(*a))
        return (0);
	tmp_a = *a;
	if ((*a)->next == *a)
		*a = NULL;
	else
	{
		*a = (*a)->next;
		(*a)->prev = tmp_a->prev;
		tmp_a->prev->next = *a;
	}
	push_to_b(b, tmp_a);
	return (1);
}
