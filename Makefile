# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/12 16:21:36 by bchaleil          #+#    #+#              #
#    Updated: 2016/02/12 17:27:22 by bchaleil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
NAME			=	fillit
FLAGS			=	-Wall -Werror -Wextra
INCLUDES		=	-I ./includes
SRCS			=	srcs/error.c\
					srcs/fill_methods.c\
					srcs/lib.c\
					srcs/get_codes.c\
					srcs/get_matrix.c\
					srcs/get_tet.c\
					srcs/main.c\
					srcs/matrix.c\
					srcs/push_list.c\
					srcs/solve.c
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

obj/%.o: srcs/%.c ./includes/lib.h
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
