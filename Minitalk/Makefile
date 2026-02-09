# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 12:06:22 by rbouquet          #+#    #+#              #
#    Updated: 2024/09/11 10:10:56 by rbouquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_C = client.c
SRC_S = server.c

NAME_C = client
NAME_S = server

#BONUS
SRC_C_BONUS = client_bonus.c
SRC_S_BONUS = server_bonus.c

NAME_C_BONUS = client_bonus
NAME_S_BONUS = server_bonus


CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -f
HEADER = -I inc

PRINTF = ft_printf
PRINTF_SRC = ft_printf/libftprintf.a

all: $(NAME_C) $(NAME_S) $(NAME_C_BONUS) $(NAME_S_BONUS)

$(NAME_C):  $(PRINTF_SRC)
	$(CC) $(FLAGS)  $(HEADER) $(SRC_C) $(PRINTF_SRC) -o $(NAME_C)

$(NAME_S):  $(PRINTF_SRC)
	$(CC) $(FLAGS)  $(HEADER) $(SRC_S) $(PRINTF_SRC) -o $(NAME_S)

#BONUS
$(NAME_C_BONUS):  $(PRINTF_SRC)
	$(CC) $(FLAGS)  $(HEADER) $(SRC_C_BONUS) $(PRINTF_SRC) -o $(NAME_C_BONUS)

$(NAME_S_BONUS):  $(PRINTF_SRC)
	$(CC) $(FLAGS)  $(HEADER) $(SRC_S_BONUS) $(PRINTF_SRC) -o $(NAME_S_BONUS)

$(PRINTF_SRC):
	$(MAKE) -C ./ft_printf

clean:
	$(MAKE) clean -C $(PRINTF)

fclean: clean
	$(RM) $(NAME_C) $(NAME_S) $(NAME_C_BONUS) $(NAME_S_BONUS)
	$(MAKE) fclean -C $(PRINTF)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re