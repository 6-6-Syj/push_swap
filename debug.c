/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-05 21:14:51 by jmagand           #+#    #+#             */
/*   Updated: 2025-02-05 21:14:51 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_and_display_header(t_stack *head)
{
	t_stack	*tmp;
	int		total_nodes;

	if (!head)
	{
		ft_printf(RED "Liste vide\n" RESET);
		return (0);
	}
	tmp = head;
	total_nodes = 1;
	while (tmp->next != head)
	{
		total_nodes++;
		tmp = tmp->next;
	}
	ft_printf(YELLOW "┌─────────────────────────────────────────┐\n" RESET);
	ft_printf(YELLOW "│                    %d                    │\n" RESET,
		total_nodes);
	ft_printf(YELLOW "└─────────────────────────────────────────┘\n" RESET);
	return (total_nodes);
}

static void	display_node(t_stack *tmp, int i)
{
	ft_printf(CYAN "   ┌────────────┐\n" RESET);
	ft_printf(CYAN "   │ " GREEN "NODE %d" CYAN "\t│\n" RESET, i);
	ft_printf(CYAN "   └───┬────────┘\n" RESET);
	ft_printf(MAGENTA "       │\n" RESET);
	ft_printf(MAGENTA "       ▼\n" RESET);
	ft_printf(BLUE "    ┌───────────┐\n" RESET);
	ft_printf(BLUE "    │ " RED "%d" BLUE "\t│\n" RESET, tmp->value);
	ft_printf(BLUE "    └───────────┘\n" RESET);
}

static void	display_end(void)
{
	ft_printf(MAGENTA "       │\n" RESET);
	ft_printf(MAGENTA "       └──┐\n" RESET);
	ft_printf(MAGENTA "          │\n" RESET);
	ft_printf(MAGENTA "          ▼\n" RESET);
	ft_printf(CYAN "   ┌────────────┐\n" RESET);
	ft_printf(CYAN "   │ " GREEN "NODE 1" CYAN "\t│\n" RESET);
	ft_printf(CYAN "   └────────────┘\n" RESET);
	ft_printf(CYAN "(retour au début)\n\n" RESET);
}

int	display_list(t_stack *head)
{
	t_stack	*tmp;
	int		total_nodes;
	int		i;

	total_nodes = count_and_display_header(head);
	if (total_nodes == 0)
		return (0);
	tmp = head;
	i = 1;
	while (1)
	{
		display_node(tmp, i);
		if (i < total_nodes)
		{
			ft_printf(MAGENTA "       │\n" RESET);
			ft_printf(MAGENTA "       ▼\n" RESET);
		}
		if (tmp->next == head)
			break ;
		i++;
		tmp = tmp->next;
	}
	display_end();
	return (1);
}
