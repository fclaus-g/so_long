/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8collectable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:05:42 by fclaus-g          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/15 14:53:03 by fclaus-g         ###   ########.fr       */
=======
/*   Updated: 2023/06/14 16:57:41 by fclaus-g         ###   ########.fr       */
>>>>>>> 995ffbe (casa 20/06)
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
			printf("coins%d\n", box->coins);
			return ;
		}
		i++;
	}
<<<<<<< HEAD
=======
	
	printf("coins: %d\n", box->coins);
	
>>>>>>> 995ffbe (casa 20/06)
	if (box->coins == 0)
		ft_open_door(box);
}

void	ft_open_door(t_box *box)
{
	int	i;

	i = 0;
	if ( box->coins == 0)
	{
		mlx_set_instance_depth(&box->E_img1->instances[0], -210);
		mlx_set_instance_depth(&box->E_img4->instances[0], 220);
	}
}
