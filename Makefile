# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/01 19:52:16 by yoaoki            #+#    #+#              #
#    Updated: 2024/06/01 19:52:18 by yoaoki           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/push_swap.c

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./lib
LIBFT_NAME = libft.a

INCLUDES = include

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCLUDES)

$(NAME): $(LIBFT) $(OBJS)
	@make -C $(LIBFT_PATH) all
	cp $(LIBFT_PATH)/$(LIBFT_NAME) $(NAME)
	$(AR) $(NAME) $(OBJS)

all: ${NAME}

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_PATH)/$(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re