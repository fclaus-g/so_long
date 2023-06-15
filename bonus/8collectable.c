/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8collectable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:05:42 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/13 11:10:04 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_quit_col(t_box *box, int y, int x)
{
	int	i;

	i = 0;
	
	while (i < box->col)
	{
		if ((box->C_img1->instances[i].x / PIX) == x / PIX && (box->C_img1->instances[i].y / PIX) == y / PIX)
		{
			box->C_img1->instances[i].enabled = false;
			box->C_img2->instances[i].enabled = false;
			box->C_img3->instances[i].enabled = false;		
		}
		i++;
	}
	printf("coins: %d\n", box->coins);
	if (box->coins == 0)
	{
		ft_open_door(box);
		ft_putstr_fd("You win!\n", 1);
	}
}

void	ft_open_door(t_box *box)
{
	int	i;

	i = 0;
	while (i < box->E_frame)
	{
		box->E_img1->instances[i].enabled = false;
		box->E_img2->instances[i].enabled = true;
		i++;
	}
}
