# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbali <bbali@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 21:43:18 by bbali             #+#    #+#              #
#    Updated: 2022/08/09 04:42:29 by bbali            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -pthread #-g
INC			=	-I ./include/
DEP_INC		=	./include/philo.h

SRC			=	main.c \
				check_args.c \
				ft_atoi.c \


OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))
SRC_DIR		=	src/
OBJ_DIR		=	.objs/

# ~~~~~~~~~~~~~~~ MANDATORY ~~~~~~~~~~~~~~~ #
all:
			@echo "$(_PURPLE_)Compiling ...$(_WHITE_)"
			@make $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $@ $^ $(LIB)
			@echo "$(_MEGAWHITE)philo ✔️$(_WHITE_)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEP_INC)
				@echo "$(_YELLOW_)$@$(_CYAN_)\r"
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(INC) -o $@ -c $< 

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ #		
clean:		
			@rm -rf $(OBJ_DIR)
			@echo "$(_RED_)[philo] object files deleted.$(_WHITE_)"

fclean:
			@make clean
			@rm -rf $(NAME)
			@echo "$(_RED_)[philo] binary file deleted.$(_WHITE_)"

re:			fclean all

# ~~~~~~~~~~~~~~~ COLOR ~~~~~~~~~~~~~~~~~~~ #
_GREEN_=\033[0;32m
_WHITE_=\033[0;37m
_MEGAWHITE=\033[1;37m
_YELLOW_=\033[1;33m
_PURPLE_=\033[0;35m
_CYAN_=\033[1;36m
_RED_=\033[0;31m

.PHONY:		all clean fclean re bonus