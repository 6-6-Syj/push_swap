/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 22:08:39 by jmagand           #+#    #+#             */
/*   Updated: 2025-02-04 22:08:39 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_letter_plus(char **av, size_t len)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i <= len)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (ft_isalpha(av[i][j]) || av[i][j] == '+')
			{
				write(2, "Error\n", 6);
				if (ft_isalpha(av[i][j]))
					ft_printf("Argument %d is incorrect: LETTER\n", i);
				else
					ft_printf("Argument [%d] is incorrect: '+'\n", i);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_format(char **av, size_t len)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i <= len)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if ((av[i][j] == '-' && j == 0 && av[i][j + 1] == '\0')
				|| (av[i][j] == '-' && j != 0))
			{
				write(2, "Error\n", 6);
				ft_printf("Argument [%d] is incorrect: '-'\n", i);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_format_2(char **av, size_t len)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i <= len)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if ((av[i][j] < 48 && av[i][j] != '-') || av[i][j] > 57)
			{
				write(2, "Error\n", 6);
				ft_printf("Argument [%d] is incorrect\n", i);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_duplicate(int *int_arr, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (int_arr[i] == int_arr[j])
			{
				write(2, "Error\n", 6);
				ft_printf("An argument got a duplicate\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
