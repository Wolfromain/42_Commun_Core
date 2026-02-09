/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:29:39 by romain            #+#    #+#             */
/*   Updated: 2024/06/07 16:15:41 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

//num
int		ft_len_int(int n);
int		ft_print_int(int n);
int		ft_print_decimal(char c);

//printf
int		ft_printf(const char *str, ...);
int		ft_types(char c, va_list args);

//tools
int		ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putnbr(int nb);

//str
int		ft_print_char(char c);
int		ft_print_str(char *str);

//ptr
int		ft_len_ptr(unsigned long ptr);
int		ft_print_ptr(unsigned long ptr);

//unsigned_int
int		ft_len_unsigned_int(unsigned int n);
int		ft_print_unsigned_int(unsigned int n);

//hexa
int		ft_len_hexa(unsigned int n);
int		ft_print_hexa_upper(unsigned int n);
int		ft_print_hexa_lower(unsigned int n);

#endif