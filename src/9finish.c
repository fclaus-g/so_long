/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9finish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:55:56 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/23 13:43:33 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_finish(t_box *box, int y, int x)
{
	//arriba
	if (box->map[(y + 15 - MOV) / PIX][(x + 30)/ PIX] == 'E' 
		&& box->map[(y + 15 - MOV) / PIX][(x + 40) / PIX] == 'E' && box->coins == 0)
	{
		ft_printf("YOU WIN");
		exit (0);
	}
	//abajo
	else if(box->map[((y + 55) + MOV) / PIX][(x + 20) / PIX] == 'E'
		&& box->map[((y + 55) + MOV) / PIX][(x + 40) / PIX] == 'E'
		&& box->coins == 0)
	{
		ft_printf("YOU WIN");
		exit (0);
	}
	else if (box->map[(y + 20) / PIX][((x + 10) - MOV) / PIX] == 'E'
		&& box->map[((y + 55)) / PIX][((x + 10) - MOV) / PIX] == 'E'
		&& box->coins == 0)
	{
		ft_printf("YOU WIN");
		exit (0);
	}
	else if (box->map[(y + 20) / PIX][((x + 45) + MOV)/ PIX] == 'E'
		&& box->map[((y + 55)) / PIX][((x + 45) + MOV) / PIX] == 'E'
		&& box->coins == 0)
	{
		ft_printf("YOU WIN");
		exit (0);
	}
}