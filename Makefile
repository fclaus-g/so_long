# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 11:13:04 by fclaus-g          #+#    #+#              #
#    Updated: 2023/05/14 11:46:37 by fclaus-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_LIB = MLX42/libmlx42.a

MLX_FLAGS = -L MLX42 -lmlx -framework OpenGL -framework AppKit

LIBFT_LIB = libft/libft.a

C_FILES = 

O_FILES = $(C_FILES:.c=.o)

all : subsystem $(NAME)

$(NAME) : $(O_FILES)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(O_FILES) $(MLX_LIB) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -lglfw -L /opt/homebrew/Cellar/glfw/3.3.6/lib/  -c $< -o $@

subsystem :
	$(MAKE) -C MLX42
	$(MAKE) -C libft

clean :
	rm -f $(O_FILES)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
