/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:44:18 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/27 16:32:20 by fclaus-g         ###   ########.fr       */
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

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RESET "\033[0m"

//ESTRUCTURAS

typedef struct s_box
{
	char 		**map;//matriz del mapa
	char 		**map2;//copia del mapa
	char		*banner_moves;
	int 		alto;//altura del mapa
	int 		ancho;//anchura del mapa
	//contadores
	int 		coins;//contador de coleccionables recogidos
	int 		col;//contador de coleccionables puestos en mapa
	int 		movs;//contador de movimientos por pixel
	int 		moves;//contador de movimientos totales
	int 		exit;//contador de salidas
	int			p_pos;//num de entradas
	int 		floor;//num de floor
	int 		wall;//num de wall
	int			enemys;
	int			enem;
	
	//posicion del player
	int			x_pos;//posicion x del player (horizontal)
	int 		y_pos;//posicion y del player (vertical)

	//frames para las animaciones
	int 		F_frame;//frame del floor
	int 		C_frame;//frame del collectible
	int			trap_frame;

	//estructuras de mlx
	mlx_t 		*mlx;//estructura de mlx
	mlx_image_t *Pr_img1;//estructura de imagen del player donde guardamos la imagen renderizada
	mlx_image_t	*Pl_img1;//izquierda
	mlx_image_t *F_img1;//estructura de imagen del floor donde guardamos la imagen renderizada
	mlx_image_t *F_img2;
	mlx_image_t *F_img3;
	mlx_image_t	*W_img;//estructura de imagen del wall donde guardamos la imagen renderizada
	mlx_image_t	*C_img1;
	mlx_image_t	*C_img2;
	mlx_image_t	*C_img3;//estructura de imagen del collectible donde guardamos la imagen renderizada
	mlx_image_t *E_img1;
	mlx_image_t *E_img4;//estructura de imagen del exit donde guardamos la imagen renderizada
	mlx_image_t *banner;
	mlx_image_t	*movement;
	mlx_image_t	*trap;
	mlx_image_t	*trap2;
}		t_box;

//FUNCIONES
//1main_bonus.c
void 		ft_hook(void *param);
void		ft_moves_control(t_box *box);
void		ft_printmap(char **map);

//2init_bonus
void		ft_readsave_map(char *str, t_box *box);
void		ft_initbox(t_box *box);
void		ft_initboxstruct(t_box *box);
void		ft_init_imgs(t_box *box);
void		ft_check_empty_line(char *str);

//3checkin_bonus.c 
int			ft_mtrlen(char **matriz);
int			ft_checkin_arg(int ac, char *str);
int 		ft_checkforma(t_box *box);
void 		ft_checkmap(t_box *box);
//3checkin_bonus2.c
int			ft_check_walls(t_box *box);
int			ft_check_elements(t_box *box);
void		ft_element_count(char c, t_box *box, int y, int x);
void		ft_flood_fill(t_box *box, int y, int x);
int			ft_way_ok(t_box *box);

//4load_images_bonus.c
void		ft_load_image(t_box *box);
void		ft_load_floor(t_box *box);
void		ft_load_col(t_box *box);
void 		ft_load_player(t_box *box);
void		ft_load_exit(t_box *box);

//5init_images_bonus.c
void		ft_render_floor(t_box *box);
void		ft_render_wall(t_box *box);
void		ft_render_col(t_box *box);
void		ft_render_exit(t_box *box);
void		ft_render_player(t_box *box);

//6animation_bonus.c
int			ft_swap_z(mlx_image_t *img1, mlx_image_t *img2, int total);
void		floor_animation(t_box *box, int timer);
void		col_animation(t_box *box, int timer);
void		enemy_animation(t_box *box, int timer);

//7player_moves_bonus1.c 8FUNCIONES
void		ft_move_P_y(t_box *box, int direccion);
void		ft_move_P_x(t_box *box, int direccion);
void		key_control(t_box *box);//34 LINEAS
void 		ft_player_direction(t_box *box, char c);
//7player_moves_bonus2.c
void		ft_move_up(t_box *box);
void		ft_move_down(t_box *box);
void		ft_move_left(t_box *box);
void		ft_move_right(t_box *box);

//8coll_and_enemy_bonus.c
void		ft_quit_col(t_box *box, int y, int x);
void		ft_open_door(t_box *box);
void		ft_load_enemy(t_box *box);
void		ft_render_enemy(t_box *box);
//9finish_bonus.c
void		ft_check_finish(t_box *box, int y, int x);
void		ft_free_so_long(t_box *box);
void		ft_free_matrix(char **matrix);
void		ft_leaks(void);
void		ft_you_win(void);
#endif