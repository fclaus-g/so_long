/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3checkin2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:47:30 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/27 16:48:22 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*en check_walls vamos a comprobar que nuestro mapa esta cerrado y rodeado de '1' recorriendolo 
caracter a caracter y si, la posicion es = 0 o = al alto o ancho -1 compruebe que sea distinto
a '1' para retornarnos (1)*/
int	ft_check_walls(t_box *box)
{
	int	x;
	int	y;

	y = 0;
	while (box->map[y])
	{
		x = 0;
		while(box->map[y][x])
		{
			//si y o x es igual a 0 o al alto o ancho -1 quiere decir que estar en el borde
			//de la cuadricula y si en esa posicion no hay un 1 quiere decir que no esta cerrado
			if (y == 0 | y == box->alto - 1 | x == 0 | x == box->ancho - 1)
			{
				if (box->map[y][x] != '1')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
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
			if (box->map2[y][x] == 'C' || box->map2[y][x] == 'P')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_flood_fill(t_box *box, int y, int x)
{
	if (y < 0 || y > box->alto || x < 0 || x > box->ancho || box->map2[y][x] == '1'
		|| box->map2[y][x] == 'F' || box->map2[y][x] == 'E')
		return ;
	if (box->map2[y][x] == 'C')
		box->map2[y][x] = '0';
	box->map2[y][x] = 'F';
	ft_flood_fill(box, y + 1, x);
	ft_flood_fill(box, y - 1, x);
	ft_flood_fill(box, y, x + 1);
	ft_flood_fill(box, y, x - 1);
}