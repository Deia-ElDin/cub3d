# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 01:42:22 by dehamad           #+#    #+#              #
#    Updated: 2024/07/15 14:58:07 by dehamad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

LIBFT_DIR = includes/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_DIR = includes/mlx

MAIN = main.c delete_me.c
PARSING = parsing.c
EXECUTION = execution.c 
UTILS = exit.c map.c 

SRCS = \
	$(addprefix src/, $(MAIN)) \
	$(addprefix src/parsing/, $(PARSING)) \
	$(addprefix src/execution/, $(EXECUTION)) \
	$(addprefix src/utils/, $(UTILS)) \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

sanitize: CFLAGS += -fsanitize=address
sanitize: all

valgrind: all
	valgrind --trace-children=yes --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --suppressions="rules/valgrind.txt" -s ./$(NAME)

libft: 
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(LIBS) -o $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re sanitize libft valgrind
