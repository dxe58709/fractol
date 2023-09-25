# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42tokyo.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/08 16:38:30 by nsakanou          #+#    #+#              #
#    Updated: 2023/09/25 17:43:39 by nsakanou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
OBJS = $(SRCS:.c=.o)

MINILIBX = libmlx.dylib

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(OBJS) $(CFLAGS) $(MINILIBX) -o $@

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

$(DEBUG):
	make all
	$(CC) $(OBJS) $(CFLAGS_DEBUG) $(MINILIBX) -o $(NAME)

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
