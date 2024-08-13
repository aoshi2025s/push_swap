# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 13:33:04 by yoaoki            #+#    #+#              #
#    Updated: 2024/08/13 14:21:20 by yoaoki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/push_swap.c\
	   src/validation.c\
	   src/stack/stack_utils.c\
	   src/stack/stack_swap.c\
	   src/stack/stack_push.c\
	   src/stack/stack_rotate.c\
	   src/stack/stack_rev_rotate.c
	
OBJS = $(SRCS:.c=.o)

NAME = push_swap
CC = cc
INCLUDE = include
LIBFT = libft
LIBFT_NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE) -I $(LIBFT)/$(INCLUDE)
RM = rm -f
# AR = ar rcs

start:
	@make -C $(LIBFT)
	@cp $(LIBFT)/$(LIBFT_NAME) .
	@make all

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT_NAME) -o $(NAME) $(OBJS)

all: ${NAME}

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)/$(LIBFT_NAME)
	$(RM) $(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re

