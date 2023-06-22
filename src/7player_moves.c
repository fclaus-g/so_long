/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7player_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:00:39 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/21 18:16:43 by fclaus-g         ###   ########.fr       */
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
void key_control(t_box *box)
{
	if (mlx_is_key_down(box->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(box->mlx);
	}
	if (mlx_is_key_down(box->mlx, MLX_KEY_W) ||
		mlx_is_key_down(box->mlx, MLX_KEY_UP))
	{
		ft_move_up(box);
		box->y_pos--;
	}
	if (mlx_is_key_down(box->mlx, MLX_KEY_S)
		|| mlx_is_key_down(box->mlx, MLX_KEY_DOWN))
	{
		ft_move_down(box);
		box->y_pos++;
	}
	if (mlx_is_key_down(box->mlx, MLX_KEY_A)
		|| mlx_is_key_down(box->mlx, MLX_KEY_LEFT))
	{
		ft_move_left(box);
		box->x_pos--;
	}
	
	if (mlx_is_key_down(box->mlx, MLX_KEY_D)
		|| mlx_is_key_down(box->mlx, MLX_KEY_RIGHT))
	{
		ft_move_right(box);
		box->x_pos++;
	}
	
	
}
/*Para mover al personaje hay que tener en cuenta que esta en una cuadricula 
referenciada por la esquina superior derecha por lo que, para evitar que se
meta en los muros tenemos que controlar las esquinas derechas (arriba y abajo)
situando el punto de referencia en ese lugar por ej mover hacia la derecha
seria: if ( box->map[(y + 60) + MOV / PIX][(x + 60) + MOV / PIX]) esta linea 
de codigo hace referencia a la esquina inferior derecha ademas el movimiento lo
hacemos usando la instancia dentro de la struct img*/
void	ft_move_up(t_box *box)
{
	int y;
	int x;

	x = box->Pr_img1->instances[0].x;
	y = box->Pr_img1->instances[0].y;
	if ((box->map[(y - MOV) / PIX][(x + 10)/ PIX] != '1' 
		&& box->map[(y - MOV) / PIX][(x + 50) / PIX] != '1'))
	{
		if (box->map[(y + 15 - MOV) / PIX][(x + 25)/ PIX] != 'E' 
			&& box->map[(y + 15 - MOV) / PIX][(x + 35) / PIX] != 'E')
			ft_move_P_y(box, -1);
	}
	if (box->map[(y + 32) / PIX][(x + 32) / PIX] == 'C')
	{
		ft_quit_col(box, y + 32, x + 32);
	}
	check_finish(box, y, x);
}

void	ft_move_down(t_box *box)
{
	int y;
	int x;

	x = box->Pr_img1->instances[0].x;
	y = box->Pr_img1->instances[0].y;
	if (box->map[((y + 60) + MOV) / PIX][(x + 10) / PIX] != '1'
		&& box->map[((y + 60) + MOV) / PIX][(x + 50) / PIX] != '1')
	{
		if(box->map[((y + 45) + MOV) / PIX][(x + 25) / PIX] != 'E'
			&& box->map[((y + 45) + MOV) / PIX][(x + 35) / PIX] != 'E')
			ft_move_P_y(box, 1);
	}
	if (box->map[(y + 32) / PIX][(x + 32) / PIX] == 'C')
	{
		ft_quit_col(box, y + 32, x + 32);
		
	}
}

void	ft_move_left(t_box *box)
{
	int y;
	int x;

	x = box->Pr_img1->instances[0].x;
	y = box->Pr_img1->instances[0].y;
	ft_player_direction(box, 'L');
	if (box->map[(y) / PIX][((x + 10) - MOV) / PIX] != '1'
		&& box->map[((y + 60)) / PIX][((x + 10) - MOV) / PIX] != '1')
	{
		if (box->map[(y + 15) / PIX][((x + 25) - MOV) / PIX] != 'E'
		&& box->map[((y + 45)) / PIX][((x + 25) - MOV) / PIX] != 'E')
		ft_move_P_x(box, -1);
	}
	if (box->map[(y + 32) / PIX][(x + 32) / PIX] == 'C')
	{
		ft_quit_col(box, y + 32, x + 32);
	}
	check_finish(box, y, x);
}

void	ft_move_right(t_box *box)
{
	int y;
	int x;

	x = box->Pr_img1->instances[0].x;
	y = box->Pr_img1->instances[0].y;
	ft_player_direction(box, 'R');
	if (box->map[(y) / PIX][((x + 50) + MOV)/ PIX] != '1'
		&& box->map[((y + 60)) / PIX][((x + 50) + MOV) / PIX] != '1')
	{
		if (box->map[(y + 15) / PIX][((x + 40) + MOV)/ PIX] != 'E'
		&& box->map[((y + 45)) / PIX][((x + 40) + MOV) / PIX] != 'E')
		ft_move_P_x(box, 1);
	}
	if (box->map[(y + 32) / PIX][(x + 32) / PIX] == 'C')
	{
		ft_quit_col(box, y + 32, x + 32);
	}
	check_finish(box, y , x);
}

void ft_player_direction(t_box *box, char c)
{
	if (c == 'R')
	{
		mlx_set_instance_depth(&box->Pr_img1->instances[0], 310);
		mlx_set_instance_depth(&box->Pl_img1->instances[0], -320);
	}
	if (c == 'L')
	{
		mlx_set_instance_depth(&box->Pr_img1->instances[0], -310);
		mlx_set_instance_depth(&box->Pl_img1->instances[0], 320);
	}
}