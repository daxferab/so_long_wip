/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 01:56:15 by daxferna          #+#    #+#             */
/*   Updated: 2024/12/27 04:20:57 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_fd_lines(int fd)
{
	char	*line;
	int		map_lines;

	map_lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		map_lines++;
		line = get_next_line(fd);
	}
	return (map_lines);
}
