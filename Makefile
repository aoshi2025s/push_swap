# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 13:33:04 by yoaoki            #+#    #+#              #
#    Updated: 2024/08/12 14:28:51 by yoaoki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/push_swap.c\
	   src/stack_utils.c\
	   src/stack_swap.c\
	   src/stack_push.c\
	   src/stack_rotate.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INCLUDE = include
# AR = ar rcs

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCLUDE)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: ${NAME}

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

