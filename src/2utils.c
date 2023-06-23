/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:55:32 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/23 18:16:29 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_empty_line(char *str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		if(str[c] == '\n' && str[c + 1] == '\n')
		{
			ft_printf("Error, parece que una linea esta vacía");
			exit (1);
		}	
		c++;
	}
}

/*en ft_readsave_map leemos dentro del .ber linea por linea gracias a gnl
y lo almacenamos en una string con todo el contenido del mapa el cual pasaremos
a una matriz con la funcion split usando como separador el "\n"*/
void	ft_readsave_map(char *str, t_box *box)
{
	int		fd;//es donde se guarda el valor de open
	char	*line;//es donde se guarda el valor de get_next_line
	char	*map_str;
	
	map_str = malloc(1 * 1);
	line = malloc(1 * 1);
	fd = open(str, O_RDONLY);
	line = get_next_line(fd);//leemos la primera linea
	if (!line)
	{
		ft_putstr_fd("Error mapa vacio", 1);
		exit (1);
	}	
	while (line)
	{
		map_str = ft_strjoin(map_str, line);//concatenamos la linea leida con la anterior
		free(line);
		line = get_next_line(fd);//leemos la siguiente linea
	}
	free(line);
	close(fd);
	check_empty_line(map_str);
	free(map_str);		
	box->map = ft_split(map_str, '\n');
	box->map2 = ft_split(map_str, '\n');
}

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
/* en intibox inicializamos las variables de nuestra caja de variables*/
void	initbox(t_box *box)
{
	box->map = NULL;
	box->map2 = NULL;
	box->ancho = 0;
	box->alto = 0;
	box->coins = 0;
	box->col = 0;
	box->movs = 0;
	box->wall = 0;
	box->floor = 0;
	box->exit = 0;
	box->p_pos = 0;
	box->x_pos = 0;
	box->y_pos = 0;
	box->F_frame = 0;
	box->C_frame = 0;
	box->E_frame = 0;
	box->P_frame = 0;
	box->mlx = NULL;
	box->F_img1 = NULL;
	box->C_img1 = NULL;
	box->E_img1 = NULL;
	box->E_img4 = NULL;
	box->Pr_img1 = NULL;
	box->Pl_img1 = NULL;
	box->W_img = NULL;
}

void printmap(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	write (1,"\n", 1);
}
