/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:11:34 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/09 12:56:59 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../MLX42/include/MLX42/MLX42.h"
#include "../lib/libft/libft.h"
#include "../lib/get_next_line/get_next_line.h"
#include "../lib/ft_printf/ft_printf.h"

# define PIX 64
# define MOV 4


//ESTRUCTURAS

typedef struct s_box
{
	char **map;//matriz del mapa
	int alto;//altura del mapa
	int ancho;//anchura del mapa
	int coins;//contador de coleccionables puestos en el mapa
	int col;//contador de coleccionables recogidos
	int movs;//contador de movimientos
	int exit;//contador de salidas
	int p_pos;//num de entradas
	int	x_pos;//posicion x del player (horizontal)
	int y_pos;//posicion y del player (vertical)
	
	mlx_t *mlx;//estructura de mlx
	mlx_image_t *P_img;//estructura de imagen del player donde guardamos la imagen renderizada
	mlx_image_t *F_img;//estructura de imagen del floor donde guardamos la imagen renderizada
	mlx_image_t	*W_img;//estructura de imagen del wall donde guardamos la imagen renderizada
	mlx_image_t	*C_img;//estructura de imagen del collectible donde guardamos la imagen renderizada
	mlx_image_t *E_img;//estructura de imagen del exit donde guardamos la imagen renderizada

}		t_box;

//FUNCIONES
//-- check_args && check map
//checkin.c
int	checkin_arg(int ac, char *str);
int	ft_mtrlen(char **matriz);
int ft_checkforma(t_box *box);
int ft_mtrlen(char **matriz);
void ft_checkmap(t_box *box);
//main.c
void	ft_readsave_map(char *str, t_box *box);
void	printmap(char **map);
//init_images.c
void	ft_init_imgs(t_box *box);
void	ft_load_image(t_box *box);
void	ft_render_img(t_box *box);
#endif