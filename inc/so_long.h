/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernandoclaus <fernandoclaus@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:11:34 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/06 17:21:32 by fernandocla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../MLX42/include/MLX42/MLX42.h"
#include "../lib/libft/libft.h"
#include "../lib/get_next_line/get_next_line.h"
#include "../lib/ft_printf/ft_printf.h"

# define IMG_H 64
# define IMG_W 64

//ESTRUCTURAS

typedef struct s_box
{
	char **map;//matriz del mapa
	int alto;//altura del mapa
	int ancho;//anchura del mapa
	int coins;//contador de coleccionables
	int movs;//contador de movimientos
	int exit;//contador de salidas
	int p_pos;//num de entradas
	int	x_pos;
	int y_pos;
}		t_box;

typedef struct s_img
{
	void *player;
	void *wall;
	void *floor;
	void *coll;
	void *exit;

}	t_img;

//FUNCIONES
//-- check_args && check map
//checkin.c
int	checkin_arg(int ac, char *str);
int	ft_mtrlen(char **matriz);
int ft_checkforma(t_box *box);
int ft_mtrlen(char **matriz);
void ft_checkmap(t_box *box);
//so_long.c
void	ft_readsave_map(char *str, t_box *box);
void	printmap(char **map);

#endif