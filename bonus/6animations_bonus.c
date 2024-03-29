/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6animations_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:41:56 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/27 16:06:38 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

/*con la funcion swap_z lo que hacemos es cambiar la instancia entre
dos imagenes multiplicando por -1 las instancias de la imagen teniendo en cuenta
que si la instancia tiene un valor positivo se convertira en negativo y viceversa 
lo que hara que se vea una imagen u otra*/
int	ft_swap_z(mlx_image_t *img1, mlx_image_t *img2, int total)
{
	int	i;
	int	depth1;
	int	depth2;

	i = 0;
	depth1 = img1->instances[i].z * - 1;
	depth2 = img2->instances[i].z * - 1;
	while (i < total)
	{
		mlx_set_instance_depth(&img1->instances[i], depth1);
		mlx_set_instance_depth(&img2->instances[i], depth2);
		i++;
	}
	return (-1);
}

void	floor_animation(t_box *box, int timer)
{
	if (box->F_frame == timer && box->F_img1->instances[0].z > 0)
		box->F_frame = ft_swap_z(box->F_img1, box->F_img2, box->floor);
	else if (box->F_frame == timer && box->F_img2->instances[0].z > 0)
		box->F_frame = ft_swap_z(box->F_img2, box->F_img1, box->floor);
	box->F_frame++;
}

void	col_animation(t_box *box, int timer)
{
	if (box->C_frame == timer && box->C_img1->instances[0].z > 0)
		box->C_frame = ft_swap_z(box->C_img1, box->C_img2, box->col);
	else if (box->C_frame == timer && box->C_img2->instances[0].z > 0)
		box->C_frame = ft_swap_z(box->C_img2, box->C_img3, box->col);
	else if (box->C_frame == timer && box->C_img3->instances[0].z > 0)
		box->C_frame = ft_swap_z(box->C_img3, box->C_img1, box->col);
	box->C_frame++;
}

void	enemy_animation(t_box *box, int timer)
{
	if (box->trap_frame == timer && box->trap->instances[0].z > 0)
		box->trap_frame = ft_swap_z(box->trap, box->trap2, box->enemys);
	else if (box->trap_frame == timer && box->trap2->instances[0].z > 0)
		box->trap_frame = ft_swap_z(box->trap2, box->trap, box->enemys);
	box->trap_frame++;
}