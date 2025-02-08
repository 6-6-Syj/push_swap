/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 17:13:01 by jmagand           #+#    #+#             */
/*   Updated: 2025-01-27 17:13:01 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

typedef struct s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				value;
}	t_stack;

//	nodes.c
t_stack	*add_new_node(int value);
void	add_node_list(t_stack **head, int value);

// debug.c
int 	display_list(t_stack *head);

//	swap.c
int		swap_a(t_stack **a);
int		swap_b(t_stack **b);
int		swap_ab(t_stack **a, t_stack **b);

// push.c
int		push_a(t_stack **a, t_stack **b);
int		push_b(t_stack **a, t_stack **b);

// rotate.c
int		rotate_a(t_stack **a);
int		rotate_b(t_stack **b);
int		rotate_ab(t_stack **a, t_stack **b);

// reverse_rotate.c
int		reverse_rotate_a(t_stack **a);
int		reverse_rotate_b(t_stack **b);
int		reverse_rotate_ab(t_stack **a, t_stack **b);

// value_to_index.c
int		*modify_value(int *arr, size_t len);

//

#endif
