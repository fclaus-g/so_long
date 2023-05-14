/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:47:53 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/05/14 13:09:18 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"

int	main()
{
	void	*mlx;
	void	*win;

	mlx = mlx_init(500, 500, "Hola", 1);
	//mlx_put_pixel(mlx, 250, 250, 0x00FF0000);
	mlx_set_window_size(mlx, 100, 100);	
	mlx_loop(mlx);
}