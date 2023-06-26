/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8collectable_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:05:42 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/26 17:09:53 by fclaus-g         ###   ########.fr       */
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
			//ft_printf("coins: %d\n", box->coins);
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
