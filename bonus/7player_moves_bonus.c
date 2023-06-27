/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7player_moves_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:00:39 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/27 16:37:43 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"


void	ft_move_P_y(t_box *box, int direccion)
{
	if (direccion > 0)
	{
		box->Pr_img1->instances[0].y += MOV;
		box->Pl_img1->instances[0].y += MOV;
		box->movs += MOV;
	}
	if (direccion < 0)
	{
		box->Pl_img1->instances[0].y -= MOV;
		box->Pr_img1->instances[0].y -= MOV;
		box->movs += MOV;
	}
		
}

void	ft_move_P_x(t_box *box, int direccion)
{
	if (direccion > 0)
	{
		box->Pr_img1->instances[0].x += MOV;	
		box->Pl_img1->instances[0].x += MOV;
		box->movs += MOV;
	}	
	if (direccion < 0)
	{
		box->Pl_img1->instances[0].x -= MOV;	
		box->Pr_img1->instances[0].x -= MOV;
		box->movs += MOV;
	}
}
/*en key control asignamos la accion a realizar al presionar la tecla, en nuestro caso cerrar la ventana 
con ESC o mover nuestro player, para mover nuestro player tenemos que usar una funcion -ft_move_P-
x o y segun queramos mov horizontal o vertical y programaremos el movimiento usando las instancias
dentro de la struct donde esta guardada nuestra imagen
typedef struct mlx_image
{
	const uint32_t	width; 
	const uint32_t	height;
	uint8_t*		pixels;
	mlx_instance_t*	instances;---es una struct con los ejes x y z con el que aplicaremos el movimiento
	int32_t			count;
	bool			enabled;
	void*			context;
}	mlx_image_t;*/
void key_control(t_box *box)
{
	if (mlx_is_key_down(box->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(box->mlx);
		exit(0);
	}
	if (mlx_is_key_down(box->mlx, MLX_KEY_W) ||
		mlx_is_key_down(box->mlx, MLX_KEY_UP))
		ft_move_up(box);
		box->y_pos--;
	if (mlx_is_key_down(box->mlx, MLX_KEY_S)
		|| mlx_is_key_down(box->mlx, MLX_KEY_DOWN))
		ft_move_down(box);
		box->y_pos++;
	if (mlx_is_key_down(box->mlx, MLX_KEY_A)
		|| mlx_is_key_down(box->mlx, MLX_KEY_LEFT))
		ft_move_left(box);
	if (mlx_is_key_down(box->mlx, MLX_KEY_D)
		|| mlx_is_key_down(box->mlx, MLX_KEY_RIGHT))
		ft_move_right(box);
}
/*Para mover al personaje hay que tener en cuenta que esta en una cuadricula 
referenciada por la esquina superior derecha por lo que, para evitar que se
meta en los muros tenemos que controlar las esquinas derechas (arriba y abajo)
situando el punto de referencia en ese lugar por ej mover hacia la derecha
seria: if ( box->map[(y + 60) + MOV / PIX][(x + 60) + MOV / PIX]) esta linea 
de codigo hace referencia a la esquina inferior derecha ademas el movimiento lo
hacemos usando la instancia dentro de la struct img*/


void ft_player_direction(t_box *box, char c)
{
	if (c == 'R')
	{
		mlx_set_instance_depth(&box->Pr_img1->instances[0], 30);
		mlx_set_instance_depth(&box->Pl_img1->instances[0], -31);
	}
	if (c == 'L')
	{
		mlx_set_instance_depth(&box->Pr_img1->instances[0], -30);
		mlx_set_instance_depth(&box->Pl_img1->instances[0], 31);
	}
}
