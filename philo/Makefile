# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 10:45:10 by hasabir           #+#    #+#              #
#    Updated: 2022/09/26 13:11:47 by hasabir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = main.c philosophers_init.c philosophers_states.c philosophers_utils.c\
	philosophers_utils_2.c

OBJ_D = obj

OBJS = $(addprefix $(OBJ_D)/,${SRCS:.c=.o}) 

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

all : ${NAME}

$(OBJ_D)/%.o: %.c | ${OBJ_D}
	@$(CC) $(CFLAGS) -c -o $@ $<

${NAME} :${OBJS}
	@$(CC) $(OBJS) -lpthread  -o $(NAME)
	@echo "|  Compilation Done  |"

${OBJ_D} :
	@mkdir ${OBJ_D}

clean:
	@rm -rf ${OBJ_D}
	@echo "|  CLEANED |"

fclean: clean
	@rm -rf ${NAME}

re: fclean all