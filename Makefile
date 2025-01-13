# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 11:21:08 by tmillot           #+#    #+#              #
#    Updated: 2025/01/13 12:59:49 by tmillot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRCS = sources/ft_printf/ft_print_pointer.c \
		sources/ft_printf/ft_printf.c \
		sources/ft_printf/ft_putnbr_count.c \
		sources/ft_printf/ft_putnbr_hexa.c \
		sources/ft_printf/ft_putstr_count.c \
		sources/pipex_utils.c \
		sources/main.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./sources/libft

LIBFT_INCLUDE = -I$(LIBFT_DIR)/includes

LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
		$(CC) $(CFLAGS) $(LIBFT_INCLUDE) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_INCLUDE) -c $< -o $@

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all
