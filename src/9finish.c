/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9finish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:55:56 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/06/27 17:04:07 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_check_finish(t_box *box, int y, int x)
{
	if (box->map[(y + 15 - MOV) / PIX][(x + 30)/ PIX] == 'E' 
		&& box->map[(y + 15 - MOV) / PIX][(x + 40) / PIX] == 'E' && box->coins == 0)
		ft_win();

	else if(box->map[((y + 55) + MOV) / PIX][(x + 20) / PIX] == 'E'
		&& box->map[((y + 55) + MOV) / PIX][(x + 40) / PIX] == 'E'
		&& box->coins == 0)
		ft_win();
	else if (box->map[(y + 20) / PIX][((x + 10) - MOV) / PIX] == 'E'
		&& box->map[((y + 55)) / PIX][((x + 10) - MOV) / PIX] == 'E'
		&& box->coins == 0)
		ft_win();
	else if (box->map[(y + 20) / PIX][((x + 45) + MOV)/ PIX] == 'E'
		&& box->map[((y + 55)) / PIX][((x + 45) + MOV) / PIX] == 'E'
		&& box->coins == 0)
		ft_win();
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
	
	ft_free_matrix(box->map);
	ft_free_matrix(box->map2);
}
void ft_win(void)
{
	ft_printf("YOU WIN");
	exit (0);
}