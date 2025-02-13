/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-12 20:00:34 by jmagand           #+#    #+#             */
/*   Updated: 2025-02-12 20:00:34 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_algo(t_stack *a, t_stack *b, size_t len, int *args)
{
	size_t	i;
	int		*index_arr;

	i = 0;
	if (len == 2)
	{
		while (i < len)
		{
			add_node_list(&a, args[i]);
			i++;
		}
		rotate_a(&a);
		return (1);
	}
	if (len > 2 && len <= 5)
	{
		while (i < len)
		{
			add_node_list(&a, args[i]);
			i++;
		}
		if (len == 3)
			algo_3(&a);
		algo_5(&a, &b, len);
		// display_list(a);
		return (1);
	}
	else
	{
		// ft_printf(RED "\n\t\tRADIX\n\n\n" RESET);
		args = rev_arr(args, len);
		index_arr = modify_value(args, len);
		while (i < len)
		{
			add_node_list(&a, index_arr[i]);
			i++;
		}
		// 	/* PRINT ARG ARRAY */

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

		algo_radix(&a, &b);
		display_list(a);

		// add_node_list(&a, 1);
		// add_node_list(&a, 2);
		// add_node_list(&a, 3);
		// add_node_list(&a, 4);
		// add_node_list(&b, 5);
		// add_node_list(&b, 6);
		// add_node_list(&b, 7);
	}
	free(index_arr);
	return (0);
}
