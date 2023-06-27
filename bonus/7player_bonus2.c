/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7player_bonus2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:58:06 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/27 16:33:57 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_move_up(t_box *box)
{
	int y;
	int x;

	x = box->Pr_img1->instances[0].x;
	y = box->Pr_img1->instances[0].y;
	if (box->map[(y - MOV) / PIX][(x + 10)/ PIX] != '1' 
		&& box->map[(y - MOV) / PIX][(x + 50) / PIX] != '1')
	{
		ft_move_P_y(box, -1);
	}
	if (box->map[(y + 32) / PIX][(x + 32) / PIX] == 'C')
	{
		ft_quit_col(box, y + 32, x + 32);
	}
	if (box->map[(y + 32) / PIX][(x + 32) / PIX] == 'X')
	{
		ft_printf(RED"YOU LOSE\n"RESET);
		ft_free_so_long(box);
		mlx_close_window(box->mlx);
		exit (1);
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
		ft_move_P_y(box, 1);
	}
	if (box->map[(y + 32) / PIX][(x + 32) / PIX] == 'C')
	{
		ft_quit_col(box, y + 32, x + 32);
	}
	if (box->map[(y + 32) / PIX][(x + 32) / PIX] == 'X')
	{
		ft_printf(RED"YOU LOSE\n"RESET);
		ft_free_so_long(box);
		mlx_close_window(box->mlx);
		exit (1);
	}
	ft_check_finish(box, y, x);
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
		ft_move_P_x(box, -1);
	}
	if (box->map[(y + 32) / PIX][(x + 32) / PIX] == 'C')
	{
		ft_quit_col(box, y + 32, x + 32);
	}
	if (box->map[(y + 32) / PIX][(x + 32) / PIX] == 'X')
	{
		ft_printf(RED"YOU LOSE\n"RESET);
		ft_free_so_long(box);
		mlx_close_window(box->mlx);
		exit (1);
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
		ft_move_P_x(box, 1);
	}
	if (box->map[(y + 32) / PIX][(x + 32) / PIX] == 'C')
	{
		ft_quit_col(box, y + 32, x + 32);
	}
	if (box->map[(y + 32) / PIX][(x + 32) / PIX] == 'X')
	{
		ft_printf(RED"\nYOU LOSE\n"RESET);
		ft_free_so_long(box);
		mlx_close_window(box->mlx);
		exit (1);
	}
	ft_check_finish(box, y, x);
}
