/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5render_images2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:53:41 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/27 17:00:58 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
				mlx_set_instance_depth(&box->C_img1->instances[box->coins], 10);
				box->coins++;
			}
			x++;
		}
		y++;
	}
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
				mlx_set_instance_depth(&box->E_img1->instances[0], 15);
				mlx_set_instance_depth(&box->E_img4->instances[0], -16);
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
				mlx_set_instance_depth(&box->Pr_img1->instances[0], 20);//damos instancia positiva para que se vea
				mlx_set_instance_depth(&box->Pl_img1->instances[0], -21);//damos instancia negativa para que no se vea
			}
			x++;
		}
		y++;
	}
}