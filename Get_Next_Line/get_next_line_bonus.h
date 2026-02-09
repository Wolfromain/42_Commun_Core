/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:32:53 by rbouquet          #+#    #+#             */
/*   Updated: 2024/06/17 11:57:45 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

//Utils
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

//GNL
char	*get_next_line(int fd);
char	*assembly(int fd, char *str);
char	*print_line(char *str);
char	*free_line(char *str);

#endif