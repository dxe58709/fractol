# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 13:34:27 by nsakanou          #+#    #+#              #
#    Updated: 2023/10/31 17:36:43 by nsakanou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# Printf+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
PRINTFDIR	=	./ft_printf
PRINTF		=	$(PRINTFDIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(PRINTFDIR)
RM = rm -f

SRCS =	atof.c \
		close_window.c \
		fractol.c \
		fractol_utils.c \
		main.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)


$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

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
