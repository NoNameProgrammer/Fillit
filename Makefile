# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egiles <egiles@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 19:32:51 by egiles            #+#    #+#              #
#    Updated: 2020/01/31 19:48:25 by egiles           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fillit
CC := gcc

SRC := main.c validation.c utils.c
OBJ := $(patsubst %.c, %.o, $(SRC))

LIB_FLAG := -Llibft/ -lft
CFLAGS := -Wall -Werror -Wextra
.PHONY: all clean fclean re

all: $(NAME)

%.o : %.c fillit.h
	@$(CC) -c $(CFLAGS) $< -o $@
	@echo $(patsubst %.c, %, $<)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) -o $(NAME) $(CFLAGS) $(LIB_FLAG) $(OBJ)
	@echo "Done"

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean $(NAME)
