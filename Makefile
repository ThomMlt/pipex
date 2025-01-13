# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 11:21:08 by tmillot           #+#    #+#              #
#    Updated: 2025/01/13 17:46:55 by tmillot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_BONUS = pipex_bonus

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRCS = sources/ft_printf/ft_print_pointer.c \
		sources/ft_printf/ft_printf.c \
		sources/ft_printf/ft_putnbr_count.c \
		sources/ft_printf/ft_putnbr_hexa.c \
		sources/ft_printf/ft_putstr_count.c \
		sources/get_next_line/get_next_line_utils.c \
		sources/get_next_line/get_next_line.c \
		sources/pipex_utils.c \

SRC_MAIN = sources/main.c

BONUS = sources/pipex_utils_bonus.c \
		sources/main_bonus.c

OBJS = $(SRCS:.c=.o)

MAIN_OBJS = ${SRC_MAIN:.c=.o}

BONUS_OBJS = ${BONUS:.c=.o}

LIBFT_DIR = ./sources/libft

LIBFT_INCLUDE = -I$(LIBFT_DIR)/includes

LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
		$(CC) $(CFLAGS) $(LIBFT_INCLUDE) ${MAIN_OBJS} $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJS} ${BONUS_OBJS}
		$(CC) $(CFLAGS) ${OBJS} ${BONUS_OBJS} $(LIBFT_INCLUDE) -L$(LIBFT_DIR) -lft -o ${NAME_BONUS}

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
