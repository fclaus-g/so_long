/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5init_images_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:25:31 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/27 16:07:11 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"
/*en primer lugar tenemos que cargar las imagenes usando una struct textura
auxiliar que igualaremos al resultado de la funcion MLX_LOAD_PNG con el path
como argumento y utilizaremos el contenido de aux para darle valor a nuestra
imagen (char *) guardada en nuestra box a traves de la funcion 
MLX_TEXTURE_TO_IMAGE tras esto vaciaremos aux para usarla de nuevo*/

/*Una vez tenos nuestras imagenes cargadas dentro de nuestra estructura
toca renderizarlas o pasarlas a la ventana, para ello rellenamos el mapa
con el fondo cuadricula a cuadricula y encima del fondo añadiremos el resto de elementos 
a razon corresponda si es muro, coleccionable, etc. Lo haremos con la funcion
MLX_IMAGE_TO_WINDOW multiplicando el num de posiciones de x o y * 64(PIX) para empezar 
a trabajar en pixeles a tener en cuenta que nuestras imagenes se cargan en el eje x e y
pero tambien contamos con el eje z para darles profundidad, para ello usamos la funcion
mlx_set_instance_depht PERO EL COMPORTAMIENTO AUN NO LO TENGO MUY CLARO PREGUNTAS:
establezco las profundidades de las imagenes en el orden en el que las cargo usando
10 para el fondo, 100 para el muro, 150 para el coleccionable y 300 para la salida
si renderizo el player en la misma funcion que el fondo, el player se renderiza
por encima del fondo pero en algunas cuadriculas se oculta, se soluciona renderizando el 
player aparte pero no entiendo porque ocurre esto, si establezco el eje z muy alto
el player desaparece, si lo establezco muy bajo se oculta en algunas cuadriculas
*/
/*IMPORTANTE PARA UNA BUENA RENDERIZACION ES INTERESANTE HACER UNA
FUNCION POR ELEMENTO PARA EVITAR ERRORES Y QUE LAS INSTANCIAS SE REFLEJEN 
O ALMACENEN BIEN
-----HAY CIERTA RELACION ENTRE EL TAMAÑO DEL MAPA Y EL EJE Z POR LO QUE
SERIA MUY RECOMENDABLE A LA HORA DE ESTABLECER EL EJE Z EN LAS INSTANCIAS NO DARLE 
MUCHA DIFERENCIA CON RESPECTO A LOS DEMAS*/
void	ft_render_floor(t_box *box)
{
	int		y;
	int		x;

	y = 0;
	while (y < box->alto)
	{
		x = 0;
		while (x < box->ancho)
		{
			mlx_image_to_window(box->mlx, box->F_img1, x * PIX, y * PIX);
			mlx_image_to_window(box->mlx, box->F_img2, x * PIX, y * PIX);
			mlx_set_instance_depth(&box->F_img1->instances[box->floor], 1);
			mlx_set_instance_depth(&box->F_img2->instances[box->floor], -2);
			box->floor++;
			x++;	
		}
		y++;
	}
}
void	ft_render_wall(t_box *box)
{
	int y;
	int x;

	y = 0;
	while (y < box->alto)
	{
		x = 0;
		while (x < box->ancho)
		{
			if (box->map[y][x] == '1')
			{
				mlx_image_to_window(box->mlx, box->W_img, x * PIX, y * PIX);
				mlx_set_instance_depth(&box->W_img->instances[box->wall], 5);
				box->wall++;
			}
			x++;
		}
		y++;
	}
}

void	ft_render_col(t_box *box)
{
	int		y;
	int		x;

	y = 0;
	while(y < box->alto)
	{
		x = 0;
		while(x < box->ancho)
		{
			if (box->map[y][x] == 'C')
			{
				mlx_image_to_window(box->mlx, box->C_img1, x * PIX, y * PIX);
				mlx_image_to_window(box->mlx, box->C_img2, x * PIX, y * PIX);
				mlx_image_to_window(box->mlx, box->C_img3, x * PIX, y * PIX);
				mlx_set_instance_depth(&box->C_img1->instances[0], 10);
				mlx_set_instance_depth(&box->C_img2->instances[0], -11);
				mlx_set_instance_depth(&box->C_img3->instances[0], -12);
				box->coins++;
			}
			x++;
		}
		y++;
	}
	box->col = box->coins;
}
void	ft_render_exit(t_box *box)
{
	int		y;
	int		x;

	y = 0;
	while(y < box->alto)
	{
		x = 0;
		while(x < box->ancho)
		{
			if (box->map[y][x] == 'E')
			{
				mlx_image_to_window(box->mlx, box->E_img1, x * PIX, y * PIX);
				mlx_image_to_window(box->mlx, box->E_img4, x * PIX, y * PIX);
				mlx_set_instance_depth(&box->E_img1->instances[0], 20);
				mlx_set_instance_depth(&box->E_img4->instances[0], -23);
			}
			x++;
		}
		y++;
	}
}
/*renderizo el player aparte para asegurarme que queda por encima de todas las capas
y no uso la funcion set_instance_depth porque se comporta igual que si lo renderizo 
con las demas imagenes, es como que la funcion no va  bien o no la uso bien o no 
comprendo el funcionamiento de el eje z
*/
void	ft_render_player(t_box *box)
{
	int	x;
	int	y;
	
	y = 0;
	while (box->map[y])
	{
		x = 0;
		while (box->map[y][x])
		{
			if (box->map[y][x] == 'P')
			{
				box->x_pos = x;
				box->y_pos = y;
				mlx_image_to_window(box->mlx, box->Pr_img1, box->x_pos * PIX, box->y_pos * PIX);
				mlx_image_to_window(box->mlx, box->Pl_img1, box->x_pos * PIX, box->y_pos * PIX);
				mlx_set_instance_depth(&box->Pr_img1->instances[0], 30);
				mlx_set_instance_depth(&box->Pl_img1->instances[0], -31);
			}
			x++;
		}
		y++;
	}
}

