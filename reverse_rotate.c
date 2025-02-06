/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 22:19:14 by jmagand           #+#    #+#             */
/*   Updated: 2025-02-04 22:19:14 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Décale d’une position vers le bas tous les élements de la pile a.
	Le dernier élément devient le premier. */
int	reverse_rotate_a(t_stack **a)
{
	if (!(*a) || (*a)->next == *a)
	return (0);
	*a = (*a)->prev;
	return (1);
}

/*	Décale d’une position vers le bas tous les élements de la pile b.
	Le dernier élément devient le premier. */
int	reverse_rotate_b(t_stack **b)
{
	if (!(*b) || (*b)->next == *b)
	return (0);
	*b = (*b)->prev;
	return (1);
}

/*	rra et rrb en même temps. */
int	reverse_rotate_ab(t_stack **a, t_stack **b)
{
	reverse_rotate_a(a);
	reverse_rotate_b(b);
	return (1);
}
