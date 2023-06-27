/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8coll_and_enemy_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:05:42 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/27 16:07:43 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

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
			box->C_img2->instances[i].enabled = false;
			box->C_img3->instances[i].enabled = false;
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
		mlx_set_instance_depth(&box->E_img1->instances[0], -15);
		mlx_set_instance_depth(&box->E_img4->instances[0], 16);
	}
}
void	ft_load_enemy(t_box *box)
{
	mlx_texture_t	*aux;

	aux = malloc(sizeof(mlx_texture_t));
	aux = mlx_load_png("sprites/enemy1.png");
	box->trap = mlx_texture_to_image(box->mlx, aux);
	mlx_delete_texture(aux);
	aux = mlx_load_png("sprites/enemy2.png");
	box->trap2 = mlx_texture_to_image(box->mlx, aux);
	mlx_delete_texture(aux);
}
void	ft_render_enemy(t_box *box)
{
	int	x;
	int	y;
	
	y = 0;
	while (box->map[y])
	{
		x = 0;
		while (box->map[y][x])
		{
			if (box->map[y][x] == 'X')
			{
				box->enemys++;
				mlx_image_to_window(box->mlx, box->trap, x * PIX, y * PIX);
				mlx_image_to_window(box->mlx, box->trap2, x * PIX, y * PIX);
				mlx_set_instance_depth(&box->trap->instances[0], 28);
				mlx_set_instance_depth(&box->trap2->instances[0], -29);
			}
			x++;
		}
		y++;
	}
}