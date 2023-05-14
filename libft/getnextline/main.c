/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:40:06 by fclaus-g          #+#    #+#             */
/*   Updated: 2022/12/23 12:23:10 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int fd2 = open("lines_around_10.txt", O_RDONLY);
		// /* 1 */ test_gnl(fd, "aaaaaaaaaa\n");
		// /* 2 */ test_gnl(fd2, "0123456789\n");
		// /* 3 */ test_gnl(fd, "bbbbbbbbbb\n");
		// /* 4 */ test_gnl(fd2, "012345678\n");
	fd = open("read_error.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	close(fd);
	close(fd2);
	system ("leaks a.out");
	return (0);
}
