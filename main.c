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

static int	is_sort(int *arr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	ft_printf("ALREADY SORTED");
	return (1);
}

static void	free_stack(t_stack **stack)
{
	t_stack	*start;
	t_stack	*current;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	start = *stack;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		if (next == start)
			break ;
		current = next;
	}
	*stack = NULL;
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	size_t	len;
	int		*args;

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
	if (!check_letter_plus(av, len) || !check_format(av, len)
		|| !check_format_2(av, len))
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
	if (is_sort(args, len))
		return (0);
	/* IF ALGO 3 OR 5 */
	choose_algo(a, b, len, args);
	// display_list(a);

	free_stack(&a);
	free_stack(&b);
	free(args);
	return (0);
}
