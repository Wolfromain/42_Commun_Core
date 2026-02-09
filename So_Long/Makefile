# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 15:27:58 by rbouquet          #+#    #+#              #
#    Updated: 2024/10/09 10:14:24 by rbouquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

RM = rm -rf

CC = cc
FLAGS = -Wall -Wextra -Werror
FLAGS_MLX = -lXext -lX11 -lm

MLX_PATH = minilibx-linux/
MLX_NAME = libmlx.a
MLX = $(addprefix $(MLX_PATH),$(MLX_NAME))

PRINTF_PATH = ft_printf/
PRINTF_NAME = libftprintf.a
PRINTF = $(addprefix $(PRINTF_PATH), $(PRINTF_NAME))

SRC = flood_fill.c free_error.c image.c init_all.c map_error.c map_error2.c player.c main.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(MLX_NAME) :
	@make -sC $(MLX_PATH)

$(PRINTF_NAME) :
	@make -sC $(PRINTF_PATH)

$(NAME) : $(OBJ) $(PRINTF_NAME) $(MLX_NAME)
	@cc $(OBJ) $(FLAGS) $(FLAGS_MLX) $(PRINTF) $(MLX) -o $(NAME)

clean :
	@rm -rf $(OBJ)
	@make clean -C $(PRINTF_PATH)
	@make clean -C $(MLX_PATH)

fclean : clean
	@rm -rf $(MLX_PATH)$(MLX_NAME)
	@rm -rf $(PRINTF_PATH)$(PRINTF_NAME)
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re