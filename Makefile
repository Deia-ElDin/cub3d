# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 01:42:22 by dehamad           #+#    #+#              #
#    Updated: 2024/08/29 16:31:07 by dehamad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -fsanitize=address -g3 -o3
SANITIZER = -fsanitize=address

LIBFT_DIR = includes/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

MLX_DIR = includes/mlx
MLX_LIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

MAIN = main.c #delete_me.c
PARSING = parsing.c validate.c utils.c
EXECUTION = execution.c movement.c raycasting.c render.c render_txture.c  old_exc.c

UTILS = exit.c init.c utils.c

SRCS = \
	$(addprefix src/, $(MAIN)) \
	$(addprefix src/parsing/, $(PARSING)) \
	$(addprefix src/execution/, $(EXECUTION)) \
	$(addprefix src/utils/, $(UTILS)) \

OBJS = $(SRCS:.c=.o)


all: $(NAME)
	./$(NAME) maps/m1.cub
	
sanitize: CFLAGS += -fsanitize=address -g3
sanitize: all

valgrind: all
	valgrind --trace-children=yes --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --suppressions="rules/valgrind.txt" -s ./minishell
	
$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean

m1:
	./$(NAME) maps/m1.cub
	
m2:
	./$(NAME) maps/m2.cub

m3:
	./$(NAME) maps/m3.cub

m4:
	./$(NAME) maps/m4.cub

m5:
	./$(NAME) maps/animals.cub

re: fclean all
	
.PHONY: all clean fclean re sanitize libft valgrind