# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/12 16:21:36 by bchaleil          #+#    #+#              #
#    Updated: 2016/01/12 16:27:47 by bchaleil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC	=\
		main.c\
		solve_fill_it.c\
		val_tet.c

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS =

all: $(NAME)

$(NAME):
	@$(CC) -c $(CFLAGS) $(SRC)
	@$(CC) -o $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all $(NAME) clean fclean re
