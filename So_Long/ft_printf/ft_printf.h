/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:29:39 by romain            #+#    #+#             */
/*   Updated: 2024/10/07 09:41:16 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

//num
int		ft_len_int(int n);
int		ft_print_int(int n);

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

//ADD
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

//GNL
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*gnl_shrink_buffer(char *buf, char *line);
char	*gnl_expand_buffer(char *buf, int fd);
char	*gnl_newread(int fd);

size_t	gnl_strlen(const char *s);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
size_t	gnl_strlcpy(char *dst, const char *src, size_t size);
int		gnl_strchr_i(const char *s, int c);
size_t	gnl_strlcat(char *dst, const char *src, size_t size);

#endif