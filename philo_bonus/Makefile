# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 10:25:15 by nasamadi          #+#    #+#              #
#    Updated: 2023/05/05 10:25:16 by nasamadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo_bonus

CC			=	gcc -g
FLAGS		=	-Wall -Wextra -Werror
RM_DIR		=	rm -rf
RM_FILE		=	rm -f
INCLUDES	= 	-I .

HEADER		=	./philo_bonus.h
SRC			=	philo_bonus.c \
				init_philo_bonus.c \
				utils_bonus.c

OBJ_DIR		=	obj
OBJ 		=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all:	$(NAME)

${NAME}:	${OBJ}
			$(CC) -o $(NAME) $(OBJ) $(FLAGS)
			@echo "\tCompiling...\t" [ $(NAME) ] $(SUCCESS)

$(OBJ)		:	| $(OBJ_DIR)

$(OBJ_DIR)	:
			@mkdir -p $(OBJ_DIR)
			
$(OBJ_DIR)/%.o :	%.c $(HEADER) Makefile
					${CC} $(FLAGS) $(INCLUDES) -o $@ -c $<

#COLORS
C_NO		=	"\033[00m"
C_OK		=	"\033[32m"
C_GOOD		=	"\033[32m"

#DEBUG
SUCCESS		=	$(C_GOOD)SUCCESS$(C_NO)
OK			=	$(C_OK)OK$(C_NO)
			
clean:
		@${RM_DIR} $(OBJ_DIR)
		@echo "\tCleaning...\t" [ $(NAME) ] $(OK)
				
fclean:	clean
		@${RM_FILE} $(NAME)
		@echo "\tDeleting...\t" [ $(NAME) ] $(OK)
				
re:		fclean all

.PHONY: all bonus clean fclean re
