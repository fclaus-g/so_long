/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernandoclaus <fernandoclaus@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:11:34 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/05/30 20:06:40 by fernandocla      ###   ########.fr       */
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
	int map_h;//altura del mapa
	int map_w;//anchura del mapa
	int coins;//contador de coleccionables
	int movs;//contador de movimientos
	int exit;//contador de salidas
	int p_pos;//posicion x del jugador
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
int	checkin(int ac, char *str);
size_t	ft_mtrlen(char **matriz);

//so_long.c
void	ft_readsave_map(char *str, t_box *box);
void	printmap(char **map);

#endif