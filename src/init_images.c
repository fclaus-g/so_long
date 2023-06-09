/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:25:31 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/09 14:14:44 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
/*en primer lugar tenemos que cargar las imagenes usando una struct textura
auxiliar que igualaremos al resultado de la funcion MLX_LOAD_PNG con el path
como argumento y utilizaremos el contenido de aux para darle valor a nuestra
imagen (char *) guardada en nuestra box a traves de la funcion 
MLX_TEXTURE_TO_IMAGE tras esto vaciaremos aux para usarla de nuevo*/
void	ft_load_image(t_box *box)
{
	mlx_texture_t	*aux;

	aux = malloc(sizeof(mlx_texture_t));
	aux = mlx_load_png("sprites/Reap1.png");
	box->P_img = mlx_texture_to_image(box->mlx, aux);
	mlx_delete_texture(aux);
	aux = mlx_load_png("sprites/bfloor2.png");
	box->F_img = mlx_texture_to_image(box->mlx, aux);
	mlx_delete_texture(aux);
	aux = mlx_load_png("sprites/wall.png");
	box->W_img = mlx_texture_to_image(box->mlx, aux);
	mlx_delete_texture(aux);
	aux = mlx_load_png("sprites/col1.png");
	box->C_img = mlx_texture_to_image(box->mlx, aux);
	mlx_delete_texture(aux);
	aux = mlx_load_png("sprites/exit1.png");
	box->E_img = mlx_texture_to_image(box->mlx, aux);
	mlx_delete_texture(aux);
}
/*Una vez tenos nuestras imagenes cargadas dentro de nuestra estructura
toca renderizarlas o pasarlas a la ventana, para ello rellenamos el mapa
con el fondo cuadricula a cuadricula y encima del fondo añadiremos el resto de elementos 
a razon corresponda si es muro, coleccionable, etc. Lo haremos con la funcion
MLX_IMAGE_TO_WINDOW multiplicando el num de posiciones de x o y * 64(PIX) para empezar 
a trabajar en pixeles*/
void	ft_render_img(t_box *box)
{
	int		y;
	int		x;

	y = 0;
	while (y < box->alto)
	{
		x = 0;
		while (x < box->ancho)
		{
			mlx_image_to_window(box->mlx, box->F_img, x * PIX, y * PIX);
			if (box->map[y][x] == '1')
				mlx_image_to_window(box->mlx, box->W_img, x * PIX, y * PIX);
			else if (box->map[y][x] == 'C')
				mlx_image_to_window(box->mlx, box->C_img, x * PIX, y * PIX);
			else if (box->map[y][x] == 'E')
				mlx_image_to_window(box->mlx, box->E_img, x * PIX, y * PIX);
			else if (box->map[y][x] == 'P')
				mlx_image_to_window(box->mlx, box->P_img, x * PIX, y * PIX);
			x++;
		}
		y++;
	}
}


void	ft_init_imgs(t_box *box)
{
	ft_load_image(box);
	ft_render_img(box);
}
