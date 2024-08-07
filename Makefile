# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vberdugo <vberdugo@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 14:20:04 by vberdugo          #+#    #+#              #
#    Updated: 2024/08/07 18:31:47 by vberdugo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFTNAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

LIBFTDIR = ./libft

SRCS = 	ft_printf.c	ft_printf_utils.c 

OBJS = $(SRCS:.c=.o)

INCLUDE = libft/libft.h ft_printf.h

all: $(NAME)

$(LIBFTDIR)/$(LIBFTNAME):
	@make -C $(LIBFTDIR)

makelibft: $(LIBFTDIR)/$(LIBFTNAME)	
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	@ar -r $(NAME) $(OBJS)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean
	
fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean
	
re: fclean all
