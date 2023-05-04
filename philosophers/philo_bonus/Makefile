# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 11:53:58 by nasamadi          #+#    #+#              #
#    Updated: 2023/05/03 16:08:14 by nasamadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRCS = main.c \
		utils.c \
		init.c \
		philo.c \

CC = cc
FLAGS = -Wall -Wextra -Werror -g -fsanitize=thread
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

re: fclean all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re
