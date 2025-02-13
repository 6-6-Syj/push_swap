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

/*	Décale d’une position vers le bas tous les élements de la pile.
	Le dernier élément devient le premier. */

int	reverse_rotate_a(t_stack **a)
{
	if (!(*a) || (*a)->next == *a)
		return (0);
	*a = (*a)->prev;
	ft_printf("rra\n");
	return (1);
}

int	reverse_rotate_b(t_stack **b)
{
	if (!(*b) || (*b)->next == *b)
		return (0);
	*b = (*b)->prev;
	ft_printf("rrb\n");
	return (1);
}
