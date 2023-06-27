/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9finish_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:55:56 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/27 16:31:21 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	ft_check_finish(t_box *box, int y, int x)
{
	if (box->map[(y + 10 - MOV) / PIX][(x + 40)/ PIX] == 'E' 
		&& box->map[(y + 10 - MOV) / PIX][(x + 50) / PIX] == 'E' 
		&& box->coins == 0)
		ft_you_win();
	else if(box->map[((y + 55) + MOV) / PIX][(x + 20) / PIX] == 'E'
		&& box->map[((y + 55) + MOV) / PIX][(x + 40) / PIX] == 'E'
		&& box->coins == 0)
		ft_you_win();
	else if (box->map[(y + 20) / PIX][((x + 10) - MOV) / PIX] == 'E'
		&& box->map[((y + 55)) / PIX][((x + 10) - MOV) / PIX] == 'E'
		&& box->coins == 0)
		ft_you_win();
	else if (box->map[(y + 20) / PIX][((x + 45) + MOV)/ PIX] == 'E'
		&& box->map[((y + 55)) / PIX][((x + 45) + MOV) / PIX] == 'E'
		&& box->coins == 0)
		ft_you_win();
}
void	ft_you_win(void)
{
	ft_printf(GREEN"\nYOU WIN\n"RESET);
	exit (0);
}
void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_free_so_long(t_box *box)
{
	mlx_delete_image(box->mlx, box->movement);
	ft_free_matrix(box->map);
	ft_free_matrix(box->map2);	
}
void	ft_leaks(void)
{
	system("leaks so_long_bonus");
}
