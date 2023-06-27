/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6player_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:00:39 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/27 16:58:24 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


void	ft_move_P_y(t_box *box, int direccion)
{
	if (direccion > 0)
	{
		box->Pr_img1->instances[0].y += MOV;
		box->Pl_img1->instances[0].y += MOV;
	}
	if (direccion < 0)
	{
		box->Pl_img1->instances[0].y -= MOV;
		box->Pr_img1->instances[0].y -= MOV;
	}
	box->movs += MOV;	
}

void	ft_move_P_x(t_box *box, int direccion)
{
	if (direccion > 0)
	{
		box->Pr_img1->instances[0].x += MOV;
		box->Pl_img1->instances[0].x += MOV;
	}	
	if (direccion < 0)
	{
		box->Pl_img1->instances[0].x -= MOV;
		box->Pr_img1->instances[0].x -= MOV;
	}
	box->movs += MOV;
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
	int32_t			count;		con respecto a las instances se creara una por cada elemento cargado
	bool			enabled;	Ej: si hay 10 monedas habra 10 instancias de monedas cada una con sus ejes
	void*			context;
}	mlx_image_t;*/
void ft_key_control(t_box *box)
{
	if (mlx_is_key_down(box->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(box->mlx);
		exit (0);
	}
	if (mlx_is_key_down(box->mlx, MLX_KEY_W) ||
		mlx_is_key_down(box->mlx, MLX_KEY_UP))
		ft_move_up(box);
	if (mlx_is_key_down(box->mlx, MLX_KEY_S)
		|| mlx_is_key_down(box->mlx, MLX_KEY_DOWN))
		ft_move_down(box);
	if (mlx_is_key_down(box->mlx, MLX_KEY_A)
		|| mlx_is_key_down(box->mlx, MLX_KEY_LEFT))
		ft_move_left(box);
	if (mlx_is_key_down(box->mlx, MLX_KEY_D)
		|| mlx_is_key_down(box->mlx, MLX_KEY_RIGHT))
		ft_move_right(box);
}

void ft_player_direction(t_box *box, char c)
{
	if (c == 'R')
	{
		mlx_set_instance_depth(&box->Pr_img1->instances[0], 20);
		mlx_set_instance_depth(&box->Pl_img1->instances[0], -21);
	}
	if (c == 'L')
	{
		mlx_set_instance_depth(&box->Pr_img1->instances[0], -20);
		mlx_set_instance_depth(&box->Pl_img1->instances[0], 21);
	}
}
