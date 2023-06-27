/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1main_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:21:51 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/27 16:32:26 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

/*esta funcion es la que engancha el bucle que mantiene la ventana abierta y
el juego en marcha, a esta funcion podemos añadirles otras funciones como el 
control de teclas para poder asignarle acciones a las teclas con la funcion
key_control*/
void ft_hook(void *param)
{
 	t_box *box;

	box = (t_box *)param;
	key_control(box);
	floor_animation(box, 100);
	if(box->enem > 0)
		enemy_animation(box, 20);
	col_animation(box, 20);
	ft_moves_control(box);
}

void	ft_moves_control(t_box *box)
{
	if (box->movs >= 64)
	{
		box->moves++;
		box->movs = 0;
		if (box->banner_moves != NULL)
			free(box->banner_moves);
		box->banner_moves = (ft_itoa(box->moves)); 
		mlx_delete_image(box->mlx, box->movement);
		box->movement = mlx_put_string(box->mlx, box->banner_moves, 200, 15);
		ft_printf(YELLOW"Movimientos:%d\r"RESET, box->moves);
	}
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
int	main(int ac, char **av)
{
	t_box	box;
	
	if (ft_checkin_arg(ac, av[1]))
		return (-1);
	atexit(ft_leaks);
	ft_initbox(&box);//iniciamos los valores de la caja
	ft_initboxstruct(&box);
	ft_readsave_map(av[1], &box);
	ft_checkmap(&box);
	box.mlx = mlx_init(box.ancho * PIX, box.alto * PIX, "so_long", 0);
	ft_init_imgs(&box);//iniciamos la carga de imagenes
	mlx_loop_hook(box.mlx, &ft_hook, &box);//enganchamos el bucle de la ventana
	mlx_loop(box.mlx);//iniciamos el bucle de la ventana
	mlx_terminate(box.mlx);//cerramos la ventana
	ft_free_so_long(&box);
	return (0);
}
/*
XXX-Las teclas W, A, S y D se utilizarán para mover al personaje principal.
XXX-El jugador debe poder moverse en 4 direcciones: subir, bajar, ir a la izquierda o ir a la derecha.
XXX-El jugador no puede entrar dentro de las paredes.
XXX-Pulsar la tecla ESC debe cerrar la ventana y cerrar el programa limpiamente.
-Hacer clic en la cruz roja de la ventana debe cerrar la ventana y terminar el programa limpiamente.
XXX-El mapa estará construido de 3 componentes: paredes, objetos y espacio abierto.
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