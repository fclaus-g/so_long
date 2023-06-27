/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4load_images_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:48:17 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/27 16:14:54 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

/*en primer lugar tenemos que cargar las imagenes usando una struct textura
auxiliar que igualaremos al resultado de la funcion MLX_LOAD_PNG con el path
como argumento y utilizaremos el contenido de aux para darle valor a nuestra
imagen (char *) guardada en nuestra box a traves de la funcion 
MLX_TEXTURE_TO_IMAGE tras esto vaciaremos aux para usarla de nuevo*/

void	ft_load_image(t_box *box)
{
	ft_load_floor(box);
	ft_load_col(box);
	ft_load_player(box);
	ft_load_exit(box);
	if (box->enem > 0)
		ft_load_enemy(box);
}

void	ft_load_floor(t_box *box)
{
	mlx_texture_t	*aux;

	aux = malloc(sizeof(mlx_texture_t));
	aux = mlx_load_png("sprites/bfloor1.png");
	box->F_img1 = mlx_texture_to_image(box->mlx, aux);
	mlx_delete_texture(aux);
	aux = mlx_load_png("sprites/bfloor2.png");
	box->F_img2 = mlx_texture_to_image(box->mlx, aux);
	mlx_delete_texture(aux);
	aux = mlx_load_png("sprites/wall.png");
	box->W_img = mlx_texture_to_image(box->mlx, aux);
	mlx_delete_texture(aux);
}

void	ft_load_col(t_box *box)
{
	mlx_texture_t	*aux;

	aux = malloc(sizeof(mlx_texture_t));
	aux = mlx_load_png("sprites/col1.png");
	box->C_img1 = mlx_texture_to_image(box->mlx, aux);
	mlx_delete_texture(aux);
	aux = mlx_load_png("sprites/col2.png");
	box->C_img2 = mlx_texture_to_image(box->mlx, aux);
	mlx_delete_texture(aux);
	aux = mlx_load_png("sprites/col3.png");
	box->C_img3 = mlx_texture_to_image(box->mlx, aux);
	mlx_delete_texture(aux);
}
void ft_load_player(t_box *box)
{
	mlx_texture_t	*aux;

	aux = malloc(sizeof(mlx_texture_t));
	aux = mlx_load_png("sprites/Reap1.png");
	box->Pr_img1 = mlx_texture_to_image(box->mlx, aux);
	mlx_delete_texture(aux);
	aux = mlx_load_png("sprites/Reapl1.png");
	box->Pl_img1 = mlx_texture_to_image(box->mlx, aux);
	mlx_delete_texture(aux);
}

void	ft_load_exit(t_box *box)
{
	mlx_texture_t	*aux;

	aux = malloc(sizeof(mlx_texture_t));
	aux = mlx_load_png("sprites/exit1.png");
	box->E_img1 = mlx_texture_to_image(box->mlx, aux);
	mlx_delete_texture(aux);
	aux = mlx_load_png("sprites/exit4.png");
	box->E_img4 = mlx_texture_to_image(box->mlx, aux);
	mlx_delete_texture(aux);
}


