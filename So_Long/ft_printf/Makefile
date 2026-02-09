# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 11:20:55 by romain            #+#    #+#              #
#    Updated: 2024/10/02 12:46:19 by rbouquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = libftprintf.a
RM = rm -f
FLAGS = -Wall -Werror -Wextra

SRC = ft_hexa.c ft_num.c ft_printf.c ft_ptr.c ft_str.c ft_strdup.c ft_strnstr.c \
	ft_tools.c ft_unsigned_int.c ft_strchr.c get_next_line_bonus.c \
	get_next_line_utils_bonus.c ft_bzero.c ft_calloc.c

OBJ = $(SRC:.c=.o)

HEADER = ft_printf.h

%.o: %.c $(HEADER)
	$(CC) -I. $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re