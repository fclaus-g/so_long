/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3checkin_bonus2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:57:47 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/27 16:11:27 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

/*en check_walls vamos a comprobar que nuestro mapa esta cerrado y rodeado de '1' recorriendolo 
caracter a caracter y si, la posicion es = 0 o = al alto o ancho -1 compruebe que sea distinto
a '1' para retornarnos (1)*/
int	ft_check_walls(t_box *box)
{
	int	c;
	int	i;

	i = 0;
	while (box->map[i])
	{
		c = 0;
		while(box->map[i][c])
		{
			if (i == 0 | i == box->alto - 1 | c == 0 | c == box->ancho - 1)
			{
				if (box->map[i][c] != '1')
					return (1);
			}
			c++;
		}
		i++;
	}
	return (0);
}
int	ft_check_elements(t_box *box)
{
	int	y;
	int x;

	y = -1;	
	while (box->map[++y])
	{
		x = -1;
		while (box->map[y][++x])
		{
			if (box->map[y][x] != 'E' && box->map[y][x] != 'P' && box->map[y][x] != 'C'
				&& box->map[y][x] != '0' && box->map[y][x] != '1' && box->map[y][x] != 'X')
				return (1);
			else
				ft_element_count(box->map[y][x], box, y, x);
		}
	}
	if (box->col < 1 || box->exit < 1 || box->p_pos != 1)
	 	return (1);
	return (0);
}
void	ft_element_count(char c, t_box *box, int y, int x)
{
	if (c == 'C')
		box->col++;
	else if (c == 'E')
		box->exit++;
	else if (c == 'X')
		box->enem++;
	else if (c == 'P')
	{
		box->p_pos++;
		box->x_pos = x;
		box->y_pos = y;
	}	
}


void	ft_flood_fill(t_box *box, int y, int x)
{
	if (y < 0 || y > box->alto || x < 0 || x > box->ancho || box->map2[y][x] == '1'
		|| box->map2[y][x] == 'F' || box->map2[y][x] == 'X')
		return ;
	if (box->map2[y][x] == 'C')
		box->map2[y][x] = '0';
	box->map2[y][x] = 'F';
	ft_flood_fill(box, y + 1, x);
	ft_flood_fill(box, y - 1, x);
	ft_flood_fill(box, y, x + 1);
	ft_flood_fill(box, y, x - 1);
}

int	ft_way_ok(t_box *box)
{
	int	x;
	int y;

	y = 0;
	while (box->map2[y])
	{
		x = 0;
		while (box->map2[y][x])
		{
			if (box->map2[y][x] == 'C' || box->map2[y][x] == 'E' || box->map2[y][x] == 'P')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
