/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-05 21:10:49 by jmagand           #+#    #+#             */
/*   Updated: 2025-02-05 21:10:49 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*add_new_node(int value)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return (NULL);
	tmp->value = value;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

void	add_node_list(t_stack **head, int value)
{
	t_stack	*new_node;
	t_stack	*tmp;

	new_node = add_new_node(value);
	if (!(*head))
	{
		(*head) = new_node;
		new_node->prev = (*head);
		new_node->next = (*head);
		return ;
	}
	tmp = *head;
	while (tmp->next != (*head))
		tmp = tmp->next;
	tmp->next = (new_node);
	new_node->prev = tmp;
	new_node->next = (*head);
	(*head)->prev = new_node;
}
