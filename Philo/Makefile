# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 09:34:39 by rbouquet          #+#    #+#              #
#    Updated: 2024/12/28 12:20:56 by rbouquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		philosophers

RM				=		rm -rf

CC				=		cc
CFLAGS			=		-Wall -Wextra -Werror

INC				=		-I ./inc/

SRC_PATH		=		src/
SRC				=		main.c \
						ft_atol.c \
						mutex.c \
						init_global.c \
						diner.c \
						set_mutex.c \
						set_time.c \
						utils.c \
						write_philo_action.c \
						checkeur.c \

SRCS			=		$(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH		=		obj/
OBJS			=		$(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRCS))

all				:		$(NAME)

$(NAME)			:		$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lpthread

$(OBJ_PATH)%.o	:		$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean			:
	$(RM) $(OBJ_PATH)

fclean			:		clean
	$(RM) $(NAME)

re			: fclean all

.PHONY			: all clean fclean re
