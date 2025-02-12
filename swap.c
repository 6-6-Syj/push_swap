/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 22:09:13 by jmagand           #+#    #+#             */
/*   Updated: 2025-02-04 22:09:13 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 	Intervertit les 2 premiers éléments au sommet de la pile.
	Ne fait rien s’il n’y en a qu’un ou aucun */

int swap_a(t_stack **a)
{
	int	tmp;

	tmp = 0;
	if (!(*a) || (*a)->next == *a)
        return (0);
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
	return (1);
}

int swap_b(t_stack **b)
{
	int	tmp;

	tmp = 0;
	if (!(*b) || (*b)->next == *b)
        return (0);
	tmp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = tmp;
	return (1);
}

int	swap_ab(t_stack **a, t_stack **b)
{
	swap_a(a);
	swap_b(b);
	return (1);
}
