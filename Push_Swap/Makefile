# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 11:21:15 by rbouquet          #+#    #+#              #
#    Updated: 2024/09/23 15:53:18 by rbouquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = push_swap
FLAGS = -Wall -Werror -Wextra
RM = rm -f
HEADER = push_swap.h

SRCS = check_error.c ft_split.c init_sort.c init_stack_a.c little_sort.c main.c push_swap.c push.c \
reverse_rotate.c rotate.c stack_utils.c stack_utils2.c swap.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	$(MAKE) $(NAME)

test:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Nombre d'opérations : "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Nombre d'opérations : "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Nombre d'opérations : "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Nombre d'opérations : "
					@./push_swap $(ARG) | wc -l

.PHONY: all clean fclean re test test3 test5 test500