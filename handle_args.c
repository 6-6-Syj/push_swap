/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 21:39:02 by jmagand           #+#    #+#             */
/*   Updated: 2025-02-10 21:39:02 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static int	check_overflow(long nb, int digit, int sign)
{
	if (sign == 1 && (nb > INT_MAX / 10
			|| (nb == INT_MAX / 10 && digit > INT_MAX % 10)))
		return (1);
	if (sign == -1 && (nb > -(long)INT_MIN / 10
			|| (nb == -(long)INT_MIN / 10 && digit > -(INT_MIN % 10))))
		return (1);
	return (0);
}

int	atoi_push_swap(const char *nptr, int *error)
{
	size_t	i;
	long	nb;
	int		sign;
	int		digit;

	nb = 0;
	digit = 0;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	sign = get_sign(&nptr);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		digit = nptr[i] - '0';
		if (check_overflow(nb, digit, sign))
		{
			*error = 1;
			return (0);
		}
		nb = nb * 10 + digit;
		i++;
	}
	return ((int)(nb * sign));
}

int	*rev_arr(int *arr, size_t len)
{
	size_t	start;
	size_t	end;
	int		tmp;

	start = 0;
	end = len - 1;
	if (!arr)
		return (NULL);
	while (start < end)
	{
		tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		start++;
		end--;
	}
	return (arr);
}

int	*stock_arg_array(char **av, size_t len)
{
	int		*arr;
	size_t	i;
	int		error;

	i = 0;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	while (i < len)
	{
		error = 0;
		arr[i] = atoi_push_swap(av[i + 1], &error);
		if (error)
		{
			free(arr);
			write(2, "Error\n", 6);
			ft_printf("An argument is not an INT\n");
			return (NULL);
		}
		i++;
	}
	return (arr);
}
