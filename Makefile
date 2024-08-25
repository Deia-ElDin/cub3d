# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
<<<<<<< HEAD
#    By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 01:42:22 by dehamad           #+#    #+#              #
#    Updated: 2024/08/15 17:49:42 by aalshafy         ###   ########.fr        #
=======
#    By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/15 14:00:58 by dehamad           #+#    #+#              #
#    Updated: 2024/08/23 18:27:39 by dehamad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes 

LIBFT_DIR = includes/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

MLX_DIR = includes/mlx
<<<<<<< HEAD
MLX_LIB = $(MLX_DIR)/libmlx.a
LIBS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

MAIN = main.c delete_me.c init.c raycasting.c render.c movement.c
PARSING = parsing.c
=======
MLX_LIB = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

MAIN = main.c delete_me.c

PARSING = parsing.c validate.c utils.c

EXECUTION = execution.c draw.c movement.c rays.c utils.c

# EXEC = execution.c movement.c rays.c render.c render2.c

UTILS = exit.c init.c utils.c mlx.c 

SRCS = \
	$(addprefix src/, $(MAIN)) \
	$(addprefix src/parsing/, $(PARSING)) \
	$(addprefix src/utils/, $(UTILS)) \
	$(addprefix src/execution/, $(EXECUTION)) \
	# $(addprefix src/exec/, $(EXEC)) \

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	./$(NAME) maps/m1.cub
>>>>>>> de3ccccf2d3c8d420dadb2f33a4832f7f10ab5bf

sanitize: CFLAGS += -fsanitize=address -g3
sanitize: re

valgrind: all
<<<<<<< HEAD
	valgrind --trace-children=yes --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --suppressions="rules/valgrind.txt" -s ./$(NAME)

libft: 
	make -C $(LIBFT_DIR)

mlx:
	make -C $(MLX_DIR)

$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(LIBS) -o $(NAME) $(SANITIZER)

$(LIBFT_LIB):
=======
	valgrind --trace-children=yes --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --suppressions="rules/valgrind.txt" -s ./minishell
	
$(NAME): $(OBJS)
>>>>>>> de3ccccf2d3c8d420dadb2f33a4832f7f10ab5bf
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

re: fclean all
	
.PHONY: all clean fclean re sanitize libft valgrind