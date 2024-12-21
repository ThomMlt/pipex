# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 11:21:08 by tmillot           #+#    #+#              #
#    Updated: 2024/12/21 11:28:32 by tmillot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = CC

CFLAGS = -Wall -Werror -Wextra -g

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft

LIBFT_INCLUDE = -I(LIBFT_DIR)/includes

LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
		$(CC) $(CFLAGS) $(LIBFT_INCLUDE) $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME)

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