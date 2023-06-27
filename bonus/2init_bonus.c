/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2init_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:55:32 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/27 16:28:58 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

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
		ft_putstr_fd(RED"Error, mapa vacio\n"RESET, 2);
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
	ft_check_empty_line(map_str);
	box->map = ft_split(map_str, '\n');
	box->map2 = ft_split(map_str, '\n');
	free(map_str);
}
/* en intibox inicializamos las variables de nuestra caja de variables*/
void	ft_initbox(t_box *box)
{
	box->map = NULL;
	box->map2 = NULL;
	box->banner_moves = NULL;
	box->ancho = 0;
	box->alto = 0;
	box->coins = 0;
	box->col = 0;
	box->movs = 0;
	box->moves = 0;
	box->exit = 0;
	box->p_pos = 0;
	box->x_pos = 0;
	box->y_pos = 0;
	box->floor = 0;
	box->wall = 0;
	box->F_frame = 0;
	box->C_frame = 0;
	box->trap_frame = 0;
	box->enemys = 0;
	box->enem = 0;
}
void	ft_initboxstruct(t_box *box)
{
	box->mlx = NULL;
	box->F_img1 = NULL;
	box->F_img2 = NULL;
	box->C_img1 = NULL;
	box->C_img2 = NULL;
	box->C_img3 = NULL;
	box->E_img1 = NULL;
	box->E_img4 = NULL;
	box->Pr_img1 = NULL;
	box->Pl_img1 = NULL;
	box->W_img = NULL;
	box->banner = NULL;
	box->movement = NULL;
	box->trap = NULL;
	box->trap2 = NULL;
}
/*en ft_init_images */
void	ft_init_imgs(t_box *box)
{
	ft_load_image(box);
	ft_render_floor(box);
	ft_render_wall(box);
	ft_render_col(box);
	ft_render_exit(box);
	ft_render_player(box);
	if (box->enem > 0)
		ft_render_enemy(box);
	box->banner = mlx_put_string(box->mlx, "Movimientos", 32, 15);
	//box->movement = mlx_put_string(box->mlx, ft_itoa(box->moves), 200, 15);
}
void	ft_check_empty_line(char *str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		if(str[c] == '\n' && str[c + 1] == '\n')
		{
			ft_putstr_fd(RED"Error, parece que una linea esta vacía\n"RESET, 2);
			exit (1);
		}	
		c++;
	}
}
