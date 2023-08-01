# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 11:13:04 by fclaus-g          #+#    #+#              #
#    Updated: 2023/07/01 19:54:53 by fclaus-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

DEF_COLOR	= \033[0;39m
VERDE		= \033[1;92m
ROJO		= \033[0;91m
AMARILLO	= \033[0;33m
AZUL		= \033[0;34m

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
libmlx:
	@echo "\n$(AMARILLO) **** Compilando MLX42 **** $(DEF_COLOR)\n"
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 
	@echo "\n$(VERDE) **** MLX42 compilada **** $(DEF_COLOR)\n"

#COMPILACION EN 42
#libmlx :
#	@make -C ${LIBMLX}

libft  :
	@echo "\n$(AMARILLO) **** Compilando LIBFT **** $(DEF_COLOR)\n"
	@make -C ${LIBFT}
	@echo "\n$(VERDE) **** LIBFT compilada **** $(DEF_COLOR)\n"
libgnl :
	@echo "\n$(AMARILLO) **** Compilando GNL **** $(DEF_COLOR)\n"
	@make -C ${LIBGNL}
	@echo "\n$(VERDE) **** GNL compilada **** $(DEF_COLOR)\n"
libpf :
	@echo "\n$(AMARILLO) **** Compilando LIBPF **** $(DEF_COLOR)\n"
	@make -C ${LIBPF}
	@echo "\n$(VERDE) **** LIBPF compilada **** $(DEF_COLOR)\n"
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<\n)"


#COMPILACION EN CASA
$(NAME): $(OBJS)
	@echo "\n$(AMARILLO) **** Compilando SO_LONG **** $(DEF_COLOR)\n"
	@$(CC) $(OBJS) $(LIBS) $(LIBFT)/libft.a $(LIBPF)/libftprintf.a $(LIBGNL)/get_next_line.a $(HEADERS) -o $(NAME)
	@echo "\n$(VERDE) **** SO_LONG compilado **** $(DEF_COLOR)\n"

#COMPILACION EN 42
#$(NAME) : $(OBJS)
#	@echo "\n$(AMARILLO) **** Compilando SO_LONG **** $(DEF_COLOR)\n"
#	${CC} $(CFLAGS) $(OBJS) $(LIBFT)/libft.a $(LIBPF)/libftprintf.a $(LIBGNL)/get_next_line.a $(LIBS42) -o $(NAME)
#	@echo "\n$(VERDE) **** SO_LONG compilado **** $(DEF_COLOR)\n"

#$(OBJ) : $(SRC)
#	$(CC) $(CFLAGS) $(SRC)

#COMPILACION BONUS EN CASA
bonus : libmlx libft libgnl libpf $(BONUSOBJ)
	@echo "\n$(AMARILLO) **** Compilando SO_LONG_BONUS **** $(DEF_COLOR)\n"
	@$(CC) $(CFLAGS) $(BONUSOBJ) $(LIBS) $(LIBFT)/libft.a $(LIBPF)/libftprintf.a $(LIBGNL)/get_next_line.a $(HEADERS) -o so_long_bonus
	@echo "\n$(VERDE) **** SO_LONG_BONUS compilado **** $(DEF_COLOR)\n"

#COMPILACION BONUS EN 42
#bonus : $(BONUSOBJ)
#	${CC} $(CFLAGS) $(BONUSOBJ) $(LIBFT)/libft.a $(LIBPF)/libftprintf.a $(LIBGNL)/get_next_line.a $(LIBS42) -o so_long_bonus

%.o: bonus/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<\n)"
	
#$(BONUSOBJ):$(BONUSSRC)	
#	$(CC) $(CFLAGS) $(BONUSSRC)

debug:
		@gcc -Wall -Wextra -Werror -g ./bonus/*.c $(LIBFT)/libft.a $(LIBPF)/libftprintf.a $(LIBGNL)/get_next_line.a \
		$(LIBS42)
		@echo "\033[0;32mArchivo debug generado"
clean:
	@echo "\n$(AZUL) **** Borrando archivos objeto **** $(DEF_COLOR)\n"
	@rm -f $(OBJS)
	@rm -f $(BONUSOBJ)
	@make clean -C ${LIBFT}
	@make clean -C ${LIBPF}
	@make clean -C ${LIBGNL}
	@make clean -C ${LIBMLX}
	@echo "\n$(VERDE) **** Archivos objeto borrados **** $(DEF_COLOR)\n"
fclean: clean
	@echo "\n$(AZUL) **** Borrando ejecutable **** $(DEF_COLOR)\n"
	@rm -f $(NAME)
	@rm -f so_long_bonus
	@make fclean -C ${LIBFT}
	@make fclean -C ${LIBPF}
	@make fclean -C ${LIBGNL}
	@make clean -C ${LIBMLX}
	@echo "\n$(VERDE) **** Ejecutable borrado **** $(DEF_COLOR)\n"

re: clean all

.PHONY: all, clean, fclean, re, libmlx
