# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/12 16:21:36 by bchaleil          #+#    #+#              #
#    Updated: 2016/01/12 17:17:31 by bchaleil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC				=	gcc
NAME			=	fillit
FLAGS			=
LIB_PATH		=	libft/
LIB				=	$(LIB_PATH)libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft
INCLUDES		=	-I $(LIB_PATH) -I ./includes
SRCS			=\
					srcs/main.c\
					srcs/solve_fill_it.c\
					srcs/val_tet.c
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


all: obj $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(FLAGS) -o $@ $^ $(LIB_LINK)
	@echo "Compiling" $(NAME) "\t\t" $(SUCCESS)

$(LIB):
	@make -C $(LIB_PATH)

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
	@make -C $(LIB_PATH) fclean
	@echo "Delete" $(NAME) "\t\t\t" $(OK)

re: fclean all

.PHONY:all $(NAME) $(LIB) obj clean fclean re
