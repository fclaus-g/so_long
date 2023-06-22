/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:44:18 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/21 12:20:31 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	//contadores
	int coins;//contador de coleccionables recogidos
	int col;//contador de coleccionables puestos en mapa
	int movs;//contador de movimientos
	int exit;//contador de salidas
	int	p_pos;//num de entradas
	int floor;//num de floor
	int wall;//num de wall
	
	//posicion del player
	int	x_pos;//posicion x del player (horizontal)
	int y_pos;//posicion y del player (vertical)

	//frames para las animaciones
	int F_frame;//frame del floor
	int C_frame;//frame del collectible
	int P_frame;//frame del player
	int E_frame;//frame del exit

	//estructuras de mlx
	mlx_t *mlx;//estructura de mlx
	mlx_image_t *Pr_img1;//estructura de imagen del player donde guardamos la imagen renderizada
	mlx_image_t	*Pr_img2;//derecha
	mlx_image_t	*Pl_img1;//izquierda
	mlx_image_t	*Pl_img2;//izquierda
	mlx_image_t *F_img1;//estructura de imagen del floor donde guardamos la imagen renderizada
	mlx_image_t *F_img2;
	mlx_image_t *F_img3;
	mlx_image_t	*W_img;//estructura de imagen del wall donde guardamos la imagen renderizada
	mlx_image_t	*C_img1;
	mlx_image_t	*C_img2;
	mlx_image_t	*C_img3;
	mlx_image_t	*C_img4;
	mlx_image_t	*C_img5;//estructura de imagen del collectible donde guardamos la imagen renderizada
	mlx_image_t *E_img1;
	mlx_image_t *E_img2;
	mlx_image_t *E_img3;
	mlx_image_t *E_img4;//estructura de imagen del exit donde guardamos la imagen renderizada
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
//load_images.c
void	ft_load_image(t_box *box);
void	ft_load_floor_and_wall(t_box *box);
void	ft_load_col(t_box *box);
void	ft_load_exit(t_box *box);
void	ft_load_player(t_box *box);

//init_images.c
void	ft_init_imgs(t_box *box);
void	ft_render_img(t_box *box);
void	ft_render_floor_and_wall(t_box *box);
void	ft_render_col(t_box *box);
void	ft_render_exit(t_box *box);
void	ft_render_player(t_box *box);
//load_images.c
void	ft_load_image(t_box *box);
void	ft_load_floor(t_box *box);
void	ft_load_col(t_box *box);
void ft_load_player(t_box *box);
void	ft_load_exit(t_box *box);

//player_moves.c
void key_control(t_box *box);
void ft_move_up(t_box *box);
void ft_move_down(t_box *box);
void ft_move_left(t_box *box);
void ft_move_right(t_box *box);
void	ft_move_P_y(t_box *box, int direccion);
void	ft_move_P_x(t_box *box, int direccion); 
//collectable.c
void	ft_quit_col(t_box *box, int y, int x);

int	ft_swap_z(mlx_image_t *img1, mlx_image_t *img2, int total);
void	floor_animation(t_box *box, int timer);
void	initbox(t_box *box);
void	ft_render_wall(t_box *box);
void	col_animation(t_box *box, int timer);
void	ft_open_door(t_box *box);
void ft_player_direction(t_box *box, char c);
void	player_animation(t_box *box, int timer, char c);
#endif