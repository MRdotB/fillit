# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/12 16:21:36 by bchaleil          #+#    #+#              #
#    Updated: 2016/01/29 01:19:28 by bchaleil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
NAME			=	fillit
FLAGS			=	-Wall -Werror -Wextra
INCLUDES		=	-I ./includes
SRCS			=\
					srcs/main.c\
					srcs/fillit.c\
					srcs/show_methods.c\
					srcs/check_error1.c\
					srcs/get_tetriminos.c\
					srcs/get_matrice.c\
					srcs/get_codes.c\
					srcs/bc_create_elem.c\
					srcs/bc_list_push.c\
					srcs/create_matrice.c\
					srcs/fill_methods.c\
					srcs/solve.c\
					srcs/ft_strlen.c\
					srcs/ft_putchar.c\
					srcs/ft_putstr.c
OBJS			=	$(SRCS:srcs/%.c=obj/%.o)

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[34m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	[ $(C_GOOD)OK$(C_NO) ]
OK				=	[ $(C_OK)OK$(C_NO) ]


all: ascii obj $(NAME)

ascii:
	@printf "%s\n%s\n%s\n%s\n%s\n%s\n" "  _____.__.__  .__  .__  __" "_/ ____\__|  | |  | |__|/  |_"  "\\   __\\|  |  | |  | |  \   __\\" " |  |  |  |  |_|  |_|  ||  |" " |__|  |__|____/____/__||__|"

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $@ $^
	@echo "Compiling" $(NAME) "\t\t" $(SUCCESS)

obj:
	@mkdir -p obj

obj/%.o: srcs/%.c ./includes/*.h
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<
	@echo "Linking" $< "\t" $(OK)

clean:
	@rm -f $(OBJS)
	@rm -rf obj
	@echo "Cleaning" $(NAME) "\t\t" $(OK)

fclean: clean
	@rm -f $(NAME)
	@echo "Delete" $(NAME) "\t\t\t" $(OK)

re: fclean all

.PHONY:all $(NAME) $(LIB) ascii obj clean fclean re
