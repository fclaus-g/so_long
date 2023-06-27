/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6player_moves2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:56:22 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/27 16:57:09 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
		if (box->map[(y + 15 - MOV) / PIX][(x + 20)/ PIX] != 'E' 
			&& box->map[(y + 15 - MOV) / PIX][(x + 40) / PIX] != 'E')
			ft_move_P_y(box, -1);
	}
	if (box->map[(y + 32) / PIX][(x + 32) / PIX] == 'C')
	{
		ft_quit_col(box, y + 32, x + 32);
	}
	ft_check_finish(box, y, x);
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
		if(box->map[((y + 55) + MOV) / PIX][(x + 25) / PIX] != 'E'
			&& box->map[((y + 55) + MOV) / PIX][(x + 35) / PIX] != 'E')
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
		if (box->map[(y + 10) / PIX][((x + 15) - MOV) / PIX] != 'E'
		&& box->map[((y + 50)) / PIX][((x + 15) - MOV) / PIX] != 'E')
		ft_move_P_x(box, -1);
	}
	if (box->map[(y + 32) / PIX][(x + 32) / PIX] == 'C')
	{
		ft_quit_col(box, y + 32, x + 32);
	}
	ft_check_finish(box, y, x);
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
		if (box->map[(y + 10) / PIX][((x + 40) + MOV)/ PIX] != 'E'
		&& box->map[((y + 50)) / PIX][((x + 40) + MOV) / PIX] != 'E')
		ft_move_P_x(box, 1);
	}
	if (box->map[(y + 32) / PIX][(x + 32) / PIX] == 'C')
	{
		ft_quit_col(box, y + 32, x + 32);
	}
	ft_check_finish(box, y , x);
}
