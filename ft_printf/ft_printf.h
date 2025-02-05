/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                         :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-21 16:51:29 by jmagand           #+#    #+#             */
/*   Updated: 2024-11-21 16:51:29 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_strlen(char *s);
int	base_len(char *base);
int	ft_putchar(char c, int fd);
int	ft_putstr(char *str, int fd);
int	ft_putnbr(int n, int fd);
int	ft_putnbr_u(unsigned int n);
int	ft_putnbr_hex(unsigned int nbr, char *base);
int	ft_putadress(void *nbr, char *base);
int	ft_putnbr_base_ul(unsigned long long nbr, char *base);

#endif
