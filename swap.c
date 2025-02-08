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
    t_stack *first;
    t_stack *second;

    if (!(*a) || (*a)->next == *a)
        return (0);
    first = *a;
    second = (*a)->next;
    if (first->next == second && second->next == first)
    {
        *a = second;
        first->next = second;
        first->prev = second;
        second->next = first;
        second->prev = first;
        return (1);
    }
    *a = second;
    first->next = second->next;
    second->next->prev = first;
    second->next = first;
    first->prev = second;
    second->prev = first->prev;
    first->prev->next = second;
    return (1);
}

int swap_b(t_stack **b)
{
    t_stack *first;
    t_stack *second;

    if (!(*b) || (*b)->next == *b)
        return (0);
    first = *b;
    second = (*b)->next;
    if (first->next == second && second->next == first)
    {
        *b = second;
        first->next = second;
        first->prev = second;
        second->next = first;
        second->prev = first;
        return (1);
    }
    *b = second;
    first->next = second->next;
    second->next->prev = first;
    second->next = first;
    first->prev = second;
    second->prev = first->prev;
    first->prev->next = second;
    return (1);
}

int	swap_ab(t_stack **a, t_stack **b)
{
	swap_a(a);
	swap_b(b);
	return (1);
}
