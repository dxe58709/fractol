# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 13:34:27 by nsakanou          #+#    #+#              #
#    Updated: 2023/10/20 19:51:07 by nsakanou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# Printf+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
PRINTFDIR	=	./printf
PRINTF		=	$(PRINTFDIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(PRINTFDIR) -g -fsanitize=address
RM = rm -f

SRCS =	circle.c \
		close.c \
		fractol.c \
		fractol_utils.c \
		ft_atoi.c \
		main.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)


$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# $(NAME): $(OBJS) $(LIBFT) 
# 	$(CC) $(OBJS) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $@

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

$(PRINTF):
	$(MAKE) -C $(PRINTFDIR) all

clean:
	$(MAKE) fclean -C $(PRINTFDIR)
	$(RM) $(OBJS)

fclean: clean
	@ make -C $(PRINTFDIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
