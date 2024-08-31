# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 01:42:22 by dehamad           #+#    #+#              #
#    Updated: 2024/08/31 11:59:14 by aalshafy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -fsanitize=address -g3
HEADER = includes/cub3d.h

LIBFT_DIR = includes/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

MLX_DIR = includes/mlx
MLX_LIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

MAIN = main.c
PARSING = parsing.c validate.c utils.c
EXECUTION = execution.c movement.c raycasting.c render.c render_txture.c
UTILS = exit.c init.c utils.c

SRCS = \
	$(addprefix src/, $(MAIN)) \
	$(addprefix src/parsing/, $(PARSING)) \
	$(addprefix src/execution/, $(EXECUTION)) \
	$(addprefix src/utils/, $(UTILS)) \

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	
sanitize: CFLAGS += -fsanitize=address -g3
sanitize: all
	
$(NAME): $(OBJS) $(HEADER)
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

m1: all
	./$(NAME) maps/m1.cub
	
m2: all
	./$(NAME) maps/m2.cub

m3: all
	./$(NAME) maps/m3.cub

m4: all
	./$(NAME) maps/m4.cub

m5: all
	./$(NAME) maps/animals.cub

re: fclean all
	
.PHONY: all clean fclean re sanitize m1 m2 m3 m4 m5