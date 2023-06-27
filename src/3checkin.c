/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3checkin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:36:46 by fernandocla       #+#    #+#             */
/*   Updated: 2023/06/27 16:50:21 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
/*en este archivo vamos a guardar las funciones necesarias para chequear 
que la entrada sea valida tanto el nombre como las caracteristicas del mapa
con check_elements vamos a recorrer nuestra matriz o mapa caracter a caracter
y vamos a sumar contadores cada vez que nos encontremos con un elemento del juego
para comprobar que hay al menos una salida, una moneda, y una posicion inicial de player
y que no hay caracteres invalidos*/

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
				&& box->map[y][x] != '0' && box->map[y][x] != '1')
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
	else if (c == 'P')
	{
		box->p_pos++;
		box->x_pos = x;
		box->y_pos = y;
	}	
}
/*en esta funcion comprobamos que hay 2 argumentos y que el nombre
del archivo es un .ber si retorna 1 el programa finalizara en el main*/
int	ft_checkin_arg(int ac, char *str)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error, argumentos incorrectos\n", 2);
		return(1);
	}
	//comparamos .ber con los ultimos 4 caracteres de la cadena s
	//no lo tengo muy visualizado pero sumandole a str la longitud de la cadena
	//y restandole 4 nos quedamos con los ultimos 4 caracteres
	if (ft_strncmp(str + ft_strlen(str) - 4, ".ber", 4) != 0)
	{
		ft_putstr_fd("Error, argumento no es .ber\n", 2);
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

	y = 0;
	weight = ft_mtrlen(box->map);
	widht = ft_strlen(box->map[y]);
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


//en checkmap vamos a llamar a las funciones anteriores para comprobar que el mapa es valido
//es el centro de control de errores
void ft_checkmap(t_box *box)
{
	if (ft_checkforma(box))
	{
		ft_putstr_fd("Error, el mapa no es rectangular\n", 2);
		exit(1);
	}
	if (ft_check_elements(box))
	{
		ft_putstr_fd("Error, el mapa no tiene los elementos necesarios\n", 2);
		exit(1);
	}
	if (ft_check_walls(box))
	{
		ft_putstr_fd("Error, el mapa no esta cerrado\n", 2);
		exit(1);
	}
	ft_flood_fill(box, box->y_pos, box->x_pos);
	if (ft_way_ok(box))
	{
		ft_putstr_fd("Error, el mapa no tiene camino válido\n", 2);
		exit(1);
	}

}
