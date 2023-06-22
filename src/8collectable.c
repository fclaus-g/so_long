/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8collectable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:05:42 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/22 14:12:12 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*removemos el coleccionable desactivando la imagen 
creamos una variable i usada en box->C_img1->instances[i].x o y porque cada moneda tiene
una instancia y asi buscamos la instancia solo de la moneda recogida.
si reduzco box->coins al pasar por encima de donde habia una moneda sigue descontando
PROBLEMA al pasar por encima de la moneda se desactiva pero sigue existiendo
ademas descuenta por pixel o por movimiento y no por cuadricula*/
void	ft_quit_col(t_box *box, int y, int x)
{
	int	i;

	i = 0;
	
	while (i < box->col)
	{
		if ((box->C_img1->instances[i].x / PIX) == x / PIX && (box->C_img1->instances[i].y / PIX) == y / PIX
			&& box->C_img1->instances[i].enabled == true)
		{
			box->C_img1->instances[i].enabled = false;
			box->coins--;
			return ;
		}
		i++;
	}
	if (box->coins == 0)
		ft_open_door(box);
}

void	ft_open_door(t_box *box)
{
	if ( box->coins == 0)
	{
		mlx_set_instance_depth(&box->E_img1->instances[0], -210);
		mlx_set_instance_depth(&box->E_img4->instances[0], 220);
	}
}
