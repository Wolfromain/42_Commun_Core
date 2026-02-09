# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 09:54:49 by rbouquet          #+#    #+#              #
#    Updated: 2025/04/07 12:40:53 by rbouquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ScavTrap

FLAG		=	-std=c++98 -Wall -Werror -Wextra

INC			=	inc/
SRC_DIR		=	src/
OBJ_DIR		=	obj/

SRC_FILES	=	main.cpp ClapTrap.cpp ScavTrap.cpp
SRCS		=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_FILES	=	$(SRC_FILES:.cpp=.o)
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	c++ $(FLAG) -I $(INC) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	c++ $(FLAG) -I $(INC) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re