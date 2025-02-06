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

int main(void)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

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
					ft_printf("\nAvant reverse_rotate_ab:\n");
					display_list(a);
					display_list(b);
					reverse_rotate_a(&a);
					ft_printf("\nAprès reverse_rotate_ab:\n");
					display_list(a);
					display_list(b);

    return (0);
}
