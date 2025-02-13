/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 22:18:47 by jmagand           #+#    #+#             */
/*   Updated: 2025-02-04 22:18:47 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Décale d’une position vers le haut tous les élements de la pile.
	Le premier élément devient le dernier.  */

int	rotate_a(t_stack **a)
{
	if (!(*a) || (*a)->next == *a)
		return (0);
	*a = (*a)->next;
	ft_printf("ra\n");
	return (1);
}

int	rotate_b(t_stack **b)
{
	if (!(*b) || (*b)->next == *b)
		return (0);
	*b = (*b)->next;
	ft_printf("rb\n");
	return (1);
}
