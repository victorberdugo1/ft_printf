# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vberdugo <vberdugo@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 14:20:04 by vberdugo          #+#    #+#              #
#    Updated: 2024/08/07 21:45:31 by victor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDE = libft/libft.h ft_printf.h

SRC = ft_printf.c ft_printf_utils.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	ar rcs $@ $^
	@cp $(LIBFT) .
	@mv libft.a $(NAME)
	@ar -r $(NAME) $(OBJ)

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJ) $(TEST_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) test_program
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re test
