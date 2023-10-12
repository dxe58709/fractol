# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/08 16:38:30 by nsakanou          #+#    #+#              #
#    Updated: 2023/10/12 17:32:11 by nsakanou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

SRCS = main.c

OBJS = $(SRCS:.c=.o)

# MINILIBX = libmlx.dylib

# Printf+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
PRINTFDIR   =   printf
PRINTF      =   $(PRINTFDIR)/libftprintf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) 
	$(CC) $(OBJS) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $@

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

#$(DEBUG):
#	make all
#	$(CC) $(OBJS) $(CFLAGS_DEBUG) $(MINILIBX) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
