# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 16:40:43 by rbouquet          #+#    #+#              #
#    Updated: 2025/03/25 09:10:46 by rbouquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		megaphone

FLAG	=		-std=c++98 -Wall -Werror -Wextra

SRC		=		Megaphone.cpp
OBJ		=		$(SRC:.cpp=.o)

CC		=		c++

%.o: $.cpp
		$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(FLAG) $(OBJ) -o $(NAME)

clean :
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re