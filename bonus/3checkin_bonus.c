/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3checkin_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:36:46 by fernandocla       #+#    #+#             */
/*   Updated: 2023/06/27 16:29:29 by fclaus-g         ###   ########.fr       */
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
/*en esta funcion comprobamos que hay 2 argumentos y que el nombre
del archivo es un .ber si retorna 1 el programa finalizara en el main*/
int	ft_checkin_arg(int ac, char *str)
{
	if (ac != 2)
	{
		ft_putstr_fd(RED"Error, argumentos incorrectos\n"RESET, 2);
		return(1);
	}
	if (ft_strncmp(str + ft_strlen(str) - 4, ".ber", 4) != 0)
	{
		ft_putstr_fd(RED"Error, argumento no es .ber\n"RESET, 2);
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


void ft_checkmap(t_box *box)
{
	if (ft_checkforma(box))
	{
		ft_putstr_fd(RED"Error, el mapa no es rectangular\n"RESET, 2);
		exit(1);
	}
	if (ft_check_elements(box))
	{
		ft_putstr_fd(RED"Error, el mapa no tiene los elementos necesarios\n"RESET, 2);
		exit(1);
	}
	if (ft_check_walls(box))
	{
		ft_putstr_fd(RED"Error, el mapa no esta cerrado\n"RESET, 2);
		exit(1);
	}
	ft_flood_fill(box, box->y_pos, box->x_pos);
	if (ft_way_ok(box))
	{
		ft_putstr_fd(RED"Error, el mapa no tiene salida\n"RESET, 2);
		exit(1);
	}
}

