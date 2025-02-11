/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 19:26:21 by jmagand           #+#    #+#             */
/*   Updated: 2025-02-04 19:26:21 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void free_stack(t_stack **stack)
{
	t_stack	*start;
	t_stack	*current;
	t_stack	*next;

	if (!stack || !*stack)
		return;
	start = *stack;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		if (next == start)
			break;
		current = next;
	}
	*stack = NULL;
}

int main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	size_t	len;
	int		*args;
	int		*index_arr;

	(void)av;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		write(2, "Error\n", 6);
		ft_printf("Need at least 2 numbers\n");
		return (0);
	}
	len = ac - 1;
	if (!check_letter_plus(av, len) || !check_format(av, len))
		return (0);
	args = stock_arg_array(av, len);
	if (!args)
		{
			write(2, "Error\n", 6);
			ft_printf("Maloc failed\n");
			return (0);
		}
	if (!check_duplicate(args, len))
	{
		free(args);
		return (0);
	}
	index_arr = modify_value(args, len);

		/* PRINT ARG ARRAY */
		size_t i = 0;
		ft_printf("ARGS_LIST\n");
		while (i != len)
		{
			ft_printf("[%d] = %d\n", i, args[i]);
			i++;
		}

		/* PRINT ARG_INDEX ARRAY */
		size_t j = 0;
		ft_printf("\nARGS_INDEX\n");
		while (j != len)
		{
			ft_printf("[%d] = %d\n", j, index_arr[j]);
			j++;
		}
		ft_printf("\n");


    add_node_list(&a, 1);
    add_node_list(&a, 2);
    add_node_list(&a, 3);
    add_node_list(&a, 4);

		add_node_list(&b, 5);
		add_node_list(&b, 6);
		add_node_list(&b, 7);

	/* SWAP_A */
    // ft_printf("\nAvant swap_a:\n");
    // display_list(a);
    // swap_a(&a);
    // ft_printf("\nAprès swap_a:\n");
    // display_list(a);

			/* SWAP_B */
			// ft_printf("\nAvant swap_b:\n");
			// display_list(b);
			// swap_b(&b);
			// ft_printf("\nAprès swap_b:\n");
			// display_list(b);

					/* SWAP_AB */
					// ft_printf("\nAvant swap_ab:\n");
					// display_list(a);
					// display_list(b);
					// swap_ab(&a, &b);
					// ft_printf("\nAprès swap_ab:\n");
					// display_list(a);
					// display_list(b);

	/* PUSH_A */
	// ft_printf("\nAvant push_a:\n");
    // display_list(a);
	// display_list(b);
    // push_a(&a, &b);
    // ft_printf("\nAprès push_a:\n");
    // display_list(a);
    // display_list(b);

			/* PUSH_B */
			// ft_printf("\nAvant push_b:\n");
			// display_list(a);
			// display_list(b);
			// push_b(&a, &b);
			// ft_printf("\nAprès push_b:\n");
			// display_list(a);
			// display_list(b);

	/* ROTATE_A */
	// ft_printf("\nAvant rotate_a:\n");
    // display_list(a);
    // rotate_a(&a);
    // ft_printf("\nAprès rotate_a:\n");
    // display_list(a);

			/* ROTATE_B */
			// ft_printf("\nAvant rotate_b:\n");
			// display_list(b);
			// rotate_b(&b);
			// ft_printf("\nAprès rotate_b:\n");
			// display_list(b);

					/* ROTATE_AB */
					// ft_printf("\nAvant rotate_ab:\n");
					// display_list(a);
					// display_list(b);
					// rotate_ab(&a, &b);
					// ft_printf("\nAprès rotate_ab:\n");
					// display_list(a);
					// display_list(b);

	/* REVERSE_ROTATE_A */
	// ft_printf("\nAvant reverse_rotate_a:\n");
	// display_list(a);
	// reverse_rotate_a(&a);
	// ft_printf("\nAprès reverse_rotate_a:\n");
	// display_list(a);

			/* REVERSE_ROTATE_B */
			// ft_printf("\nAvant reverse_rotate_b:\n");
			// display_list(b);
			// reverse_rotate_b(&b);
			// ft_printf("\nAprès reverse_rotate_b:\n");
			// display_list(b);

					/* REVERSE_ROTATE_AB */
					// ft_printf("\nAvant reverse_rotate_ab:\n");
					// display_list(a);
					// display_list(b);
					// reverse_rotate_ab(&a, &b);
					// ft_printf("\nAprès reverse_rotate_ab:\n");
					// display_list(a);
					// display_list(b);

	free_stack(&a);
	free_stack(&b);
	free(args);
	return (0);

}
