/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:21:51 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/08 18:31:39 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/so_long.h"
#include "../MLX42/include/MLX42/MLX42.h"

/*con key_control añadimos funcionalidades a las teclas como cerrar la ventana si
presionamos escape o mover nuestro player si presionas una u otra tecla*/
void key_control(t_box *box)
{
	if (mlx_is_key_down(box->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(box->mlx);
	}
	if (mlx_is_key_down(box->mlx, MLX_KEY_W))
	{
		box->y_pos--;
	}
	if (mlx_is_key_down(box->mlx, MLX_KEY_S))
	{
		box->y_pos++;
	}
	if (mlx_is_key_down(box->mlx, MLX_KEY_A))
	{
		box->x_pos--;
	}
	
	if (mlx_is_key_down(box->mlx, MLX_KEY_D))
	{
		box->x_pos++;
	}
	
}
/*esta funcion es la que engancha el bucle que mantiene la ventana abierta y
el juego en marcha, a esta funcion podemos añadirles otras funciones como el 
control de teclas para poder asignarle acciones a las teclas con la funcion
key_control*/
void ft_hook(void *param)
{
 	t_box *box;

	box = (t_box *)param;
	key_control(box);
}
void printmap(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	write (1,"\n", 1);
}

/*en ft_readsave_map leemos dentro del .ber linea por linea gracias a gnl
y lo almacenamos en una string con todo el contenido del mapa el cual pasaremos
a una matriz con la funcion split usando como separador el "\n"*/
void	ft_readsave_map(char *str, t_box *box)
{
	int		fd;//es donde se guarda el valor de open
	char	*line;//es donde se guarda el valor de get_next_line
	char	*map_str;
	
	map_str = malloc(1 * 1);
	line = malloc(1 * 1);
	fd = open(str, O_RDONLY);
	line = get_next_line(fd);//leemos la primera linea
	while (line)
	{
		map_str = ft_strjoin(map_str, line);//concatenamos la linea leida con la anterior
		free(line);
		line = get_next_line(fd);//leemos la siguiente linea
	}
	free(line);
	close(fd);
	box->map = ft_split(map_str, '\n');
	free(map_str);
	printmap(box->map);
}
/* en intibox inicializamos las variables de nuestra caja de variables*/
void	initbox(t_box *box)
{
	box->map = NULL;
	box->ancho = 0;
	box->alto = 0;
	box->coins = 0;
	box->col = 0;
	box->movs = 0;
	box->exit = 0;
	box->p_pos = 0;
	box->x_pos = 0;
	box->y_pos = 0;
	box->mlx = NULL;
	box->F_img = NULL;
	box->C_img = NULL;
	box->E_img = NULL;
	box->P_img = NULL;
	box->W_img = NULL;
}

int	main(int ac, char **av)
{
	t_box	box;
	if (checkin_arg(ac, av[1]))
		return (-1);
	initbox(&box);//iniciamos los valores de la caja
	ft_readsave_map(av[1], &box);
	ft_checkmap(&box);
	box.mlx = mlx_init(box.ancho * PIX, box.alto * PIX, "so_long", 0);
	ft_init_imgs(&box);//iniciamos la carga de imagenes
	mlx_loop_hook(box.mlx, ft_hook, &box);
	mlx_loop(box.mlx);
	mlx_terminate(box.mlx);
	//mlx_loop_hook(mlx, ft_hook, mlx);
	return (0);
}
/*
-Las teclas W, A, S y D se utilizarán para mover al personaje principal.
-El jugador debe poder moverse en 4 direcciones: subir, bajar, ir a la izquierda o ir a la derecha.
-El jugador no puede entrar dentro de las paredes.
-Pulsar la tecla ESC debe cerrar la ventana y cerrar el programa limpiamente.
-Hacer clic en la cruz roja de la ventana debe cerrar la ventana y terminar el programa limpiamente.
-El mapa estará construido de 3 componentes: paredes, objetos y espacio abierto.
XXX-El mapa estará compuesto de solo 5 caracteres: 0 para un espacio vacío, 1 para un muro, C para un 
coleccionable, E para salir del mapa y P para la posición inicial del jugador.
XXX-El mapa debe tener una salida, al menos un objeto y una posición inicial.
XXX-El mapa debe ser rectangular.
XXX-El mapa deberá estar cerrado/rodeado de muros, en caso contrario el programa deberá devolver un error.
-Tienes que comprobar si hay un camino válido en el mapa.
-En caso de fallos de configuración de cualquier tipo encontrados en el archivo, el programa debe
 terminar correctamente y devolver “Error\n” seguido de un mensaje explícito de tu elección.
 --BONUS--
-Haces que el jugador pierda cuando toque una patrulla de enemigos
-Añades algunas animaciones de sprites.
-Muestras el contador de movimiento directamente en la pantalla en lugar de en el terminal.
 */