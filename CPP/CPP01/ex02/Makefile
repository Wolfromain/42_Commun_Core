# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 13:43:34 by rbouquet          #+#    #+#              #
#    Updated: 2025/03/25 13:55:02 by rbouquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	zombie

FLAG		=	-std=c++98 -Wall -Werror -Wextra

OBJ_DIR		=	obj/

SRCS		=	main.cpp

OBJ_FILES	=	$(SRCS:.cpp=.o)
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	c++ $(FLAG) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	c++ $(FLAG) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re