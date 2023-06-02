/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernandoclaus <fernandoclaus@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:36:46 by fernandocla       #+#    #+#             */
/*   Updated: 2023/05/30 20:21:52 by fernandocla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
/*en esta funcion comprobamos que hay 2 argumentos y que el nombre
del archivo es un .ber si retorna 1 el programa finalizara en el main*/
int	checkin(int ac, char *str)
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

void ft_checkmap(t_box *box)
