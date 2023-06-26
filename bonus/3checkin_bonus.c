/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3checkin_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:36:46 by fernandocla       #+#    #+#             */
/*   Updated: 2023/06/26 16:26:36 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"
/*en este archivo vamos a guardar las funciones necesarias para chequear 
que la entrada sea valida tanto el nombre como las caracteristicas del mapa*/
int	ft_mtrlen(char **matriz)
{
	int	i;

	i = 0;
	if (matriz == NULL)
		return (0);
	while (matriz[i] != NULL)
		i++;
	return (i);
}

/*con check_elements vamos a recorrer nuestra matriz o mapa caracter a caracter
y vamos a sumar contadores cada vez que nos encontremos con un elemento del juego
para comprobar que hay al menos una salida, una moneda, y una posicion inicial de player
y que no hay caracteres invalidos*/

int	ft_check_elements(t_box *box)
{
	int	y;
	int x;

	y = 0;
	
	while (box->map[y])
	{
		x = 0;
		while (box->map[y][x])
		{
			if (box->map[y][x] != 'E' && box->map[y][x] != 'P' && box->map[y][x] != 'C' \
				&& box->map[y][x] != '0' && box->map[y][x] != '1')
				return (1);
			else if (box->map[y][x] == 'C')
				box->col++;
			else if (box->map[y][x] == 'E')
				box->exit++;
			else if (box->map[y][x] == 'P')
			{
				box->p_pos++;
				box->x_pos = x;
				box->y_pos = y;
			}	
			x++;
		}
		y++;
	}
	if (box->col < 1 || box->exit < 1 || box->p_pos != 1)
	 	return (1);
	return (0);
}
/*en esta funcion comprobamos que hay 2 argumentos y que el nombre
del archivo es un .ber si retorna 1 el programa finalizara en el main*/
int	ft_checkin_arg(int ac, char *str)
{
	if (ac != 2)
	{
		ft_printf("Error argumentos incorrectos\n");
		return(1);
	}
	if (ft_strncmp(str + ft_strlen(str) - 4, ".ber", 4) != 0)
	{
		ft_printf("Error argumento no es .ber\n");
		return(1);
	}
	return (0);
}

/* en checkforma vamos a comprobar que el mapa es rectangular y que todas las filas tienen 
la misma longitud por lo que si alto y ancho son iguales o */
int	ft_checkforma(t_box *box)
{
	int y;//contador de filas
	int	widht;//anchura
	int	weight;//altura

	widht = ft_strlen(box->map[0]);
	weight = ft_mtrlen(box->map);
	y = 0;
	if (widht == weight)
		return (1);
	while (box->map[y])
	{
		if (ft_strlen(box->map[y]) != (size_t)widht)
			return (1);
		y++;
	}
	box->ancho = widht;
	box->alto = weight;
	return (0);
}
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

void ft_checkmap(t_box *box)
{
	if (ft_checkforma(box))
	{
		ft_printf("Error el mapa no es rectangular\n");
		exit(1);
	}
	if (ft_check_elements(box))
	{
		ft_printf("Error el mapa no tiene los elementos necesarios\n");
		exit(1);
	}
	if (ft_check_walls(box))
	{
		ft_printf("Error el mapa no esta cerrado\n");
		exit(1);
	}

}
