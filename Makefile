# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 11:13:04 by fclaus-g          #+#    #+#              #
#    Updated: 2023/06/22 14:14:35 by fclaus-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

#DIRECTORIOS
LIBMLX	= ./MLX42
LIBFT	= ./lib/libft
LIBPF	= ./lib/ft_printf
LIBGNL	= ./lib/get_next_line

#COMPILADOR
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -Ofast 
HEADERS	= -I ./include -I $(LIBMLX)/include/MLX42/ -I $(LIBFT) -I $(LIBGNL) -I $(LIBPF)#esto es para que busque los .h en la carpeta include
LIBS	= $(LIBMLX)/build/libmlx42.a -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"
LIBS42	= -framework Cocoa -framework OpenGL -framework IOKit $(LIBMLX)/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
CC		= gcc
SRCS	= $(shell find ./src -iname "*.c")
OBJS	= ${SRCS:.c=.o}
BONUSSRC = ${shell find ./bonus -iname "*.c"}
BONUSOBJ = ${BONUSSRC:.c=.o}

all: libmlx libft libgnl libpf $(NAME)

#COMPILACION EN CASA
#libmlx:
#	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 

#COMPILACION EN 42
libmlx :
	@make -C ${LIBMLX}

libft  :
	@make -C ${LIBFT}
libgnl :
	@make -C ${LIBGNL}
libpf :
	@make -C ${LIBPF}
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<\n)"


#COMPILACION EN CASA
#$(NAME): $(OBJS)
#	@$(CC) $(OBJS) $(LIBS) $(LIBFT)/libft.a $(LIBPF)/libftprintf.a $(LIBGNL)/get_next_line.a $(HEADERS) -o $(NAME)

#COMPILACION EN 42
$(NAME) : $(OBJS)
	${CC} $(CFLAGS) $(OBJS) $(LIBFT)/libft.a $(LIBPF)/libftprintf.a $(LIBGNL)/get_next_line.a $(LIBS42) -o $(NAME)

#$(OBJ) : $(SRC)
#	$(CC) $(CFLAGS) $(SRC)

bonus : libmlx libft libgnl libpf $(BONUSOBJ)
	${CC} $(CFLAGS) $(BONUSOBJ) $(LIBFT)/libft.a $(LIBPF)/libftprintf.a $(LIBGNL)/get_next_line.a $(LIBS42) -o so_long_bonus

%.o: bonus/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<\n)"
	
#$(BONUSOBJ):$(BONUSSRC)	
#	$(CC) $(CFLAGS) $(BONUSSRC)

debug:
		@gcc -Wall -Wextra -Werror -g ./src/*.c $(LIBFT)/libft.a $(LIBPF)/libftprintf.a $(LIBGNL)/get_next_line.a \
		$(LIBS42)
		@echo "\033[0;32mArchivo debug generado"
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
