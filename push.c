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

// void	push_a(t_stack **a, t_stack **b)
// {
// /* 	Prend le premier élément au sommet de b et le met sur a.
// 	Ne fait rien si b est vide. */
// 	stack_len(a);
// }

// void	push_b(t_stack **b,  t_stack **a)
// {
// /* 	Prend le premier élément au sommet de a et le met sur b.
// 	Ne fait rien si a est vide. */
// }

// int	stack_len(t_stack *a) // LISTE CHAINEE SIMPLE
// {
// 	int	len;

// 	len = 1;
// 	if (!a)
// 		return (0);
// 	while (a->next != NULL)
// 	{
// 		len++;
// 		a = a->next;
// 	}
// 	return (len);
// }

// size_t	stack_len2(t_stack *a)
// {
// 	int		len;
// 	t_stack	*tmp;

// 	len = 1;
// 	if (!a)
// 		return (0);
// 	tmp = a;
// 	while (tmp->next != a)
// 	{
// 		len++;
// 		tmp = tmp->next;
// 	}
// 	return (len);
// }

t_stack	*add_new_node(int value)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return (NULL);
	tmp->content = value;
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

void display_list(t_stack *head)
{
    if (!head)
    {
        ft_printf(RED "Liste vide\n" RESET);
        return;
    }

    t_stack *tmp = head;
    int i = 1;
    int total_nodes = 1;

    // Compter le nombre total de nœuds
    while (tmp->next != head)
    {
        total_nodes++;
        tmp = tmp->next;
    }

    ft_printf(YELLOW "┌─────────────────────────────────────────┐\n" RESET);
    ft_printf(YELLOW "│      Liste Chaînée Circulaire (%d)       │\n" RESET, total_nodes);
    ft_printf(YELLOW "└─────────────────────────────────────────┘\n" RESET);

    tmp = head;
    while (1)
    {
        ft_printf(CYAN "   ┌────────────┐\n" RESET);
        ft_printf(CYAN "   │ " GREEN "NODE %d" CYAN "\t│\n" RESET, i);
        ft_printf(CYAN "   └───┬────────┘\n" RESET);
        ft_printf(MAGENTA "       │\n" RESET);
        ft_printf(MAGENTA "       ▼\n" RESET);
        ft_printf(BLUE "    ┌───────────┐\n" RESET);
        ft_printf(BLUE "    │ " RED "%d" BLUE "\t│\n" RESET, tmp->content);
        ft_printf(BLUE "    └───────────┘\n" RESET);

        if (i < total_nodes)
        {
            ft_printf(MAGENTA "       │\n" RESET);
            ft_printf(MAGENTA "       ▼\n" RESET);
        }

        if (tmp->next == head)
            break;

        i++;
        tmp = tmp->next;
    }

    ft_printf(MAGENTA "       │\n" RESET);
    ft_printf(MAGENTA "       └──┐\n" RESET);
    ft_printf(MAGENTA "          │\n" RESET);
    ft_printf(MAGENTA "          ▼\n" RESET);
    ft_printf(CYAN "   ┌────────────┐\n" RESET);
    ft_printf(CYAN "   │ " GREEN "NODE 1" CYAN "\t│\n" RESET);
    ft_printf(CYAN "   └────────────┘\n" RESET);
    ft_printf(CYAN "(retour au début)\n\n" RESET);
}

// void	display_list(t_stack *head)
// {
// 	t_stack	*tmp;
// 	int		i;

// 	tmp = head;
// 	i = 1;
// 	while (tmp->next != head)
// 	{
// 		ft_printf("NODE %d\n   |\n   v\n  [%d]\n", i, tmp->content);
// 		ft_printf("   |\n   v\n");
// 		i++;
// 		tmp = tmp->next;
// 	}
// 	ft_printf("NODE %d\n   |\n   v\n  [%d]\n", i, tmp->content);
// 	tmp = tmp->next;
// 	ft_printf("   |\n   v\n");
// 	ft_printf("NODE 1\n   |\n   v\n  [%d]\n", tmp->content);
// }

int main(void)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    add_node_list(&a, 1);
    add_node_list(&a, 2);

    add_node_list(&b, 1);
    add_node_list(&b, 2);

    // ft_printf("\nAvant swap_a:\n");
    // display_list(a);
    // swap_a(&a);
    // ft_printf("\nAprès swap_a:\n");
    // display_list(a);

    // ft_printf("\nAvant swap_b:\n");
    // display_list(b);
    // swap_b(&b);
    // ft_printf("\nAprès swap_b:\n");
    // display_list(b);

	ft_printf("\nAvant swap_ab:\n");
    display_list(a);
	display_list(b);
    swap_ab(&a, &b);
    ft_printf("\nAprès swap_ab:\n");
    display_list(a);
    display_list(b);

    return (0);
}

