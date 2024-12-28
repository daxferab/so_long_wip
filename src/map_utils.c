/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 01:56:15 by daxferna          #+#    #+#             */
/*   Updated: 2024/12/28 06:05:35 by daxferna         ###   ########.fr       */
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

int	get_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

bool	is_wall(char *map_line)
{
	int	i;

	i = 0;
	while (map_line[i] != '\n')
	{
		if (map_line[i] != WALL)
			return (false);
		i++;
	}
	return (true);
}

bool	has_mandatory_elements(char	**map)
{
	int		i;
	int		j;
	int		player;
	int		exit;
	bool	collectible;

	i = 0;
	player = 0;
	exit = 0;
	collectible = false;
	while (map[i])
	{
		j = 0;
		while (map[i][j++])
		{
			if (map[i][j - 1] == PLAYER)
				player++;
			if (map[i][j - 1] == EXIT)
				exit++;
			if (map[i][j - 1] == COLLECTIBLE)
				collectible = true;
		}
		i++;
	}
	return (player == 1 && exit == 1 && collectible);
}
