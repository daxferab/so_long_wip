/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:17:07 by daxferna          #+#    #+#             */
/*   Updated: 2024/12/26 04:01:56 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	map_to_matrix(int fd, char **map, char *arg)
{
	char	*line;
	int		i;
	int		map_lines;

	i = 0;

	map_lines = malloc_map_lines(fd, map);
	if (!map || map_lines < 3)
		return (free(map), false);
	fd = open(arg, O_RDONLY);
	while (i < map_lines)
	{
		line = get_next_line(fd);
		if (!line)
			return (close(fd), free_map(map), false);
		map[i] = malloc(ft_strlen(line) + 1);
		if (!map[i])
			return (close(fd), free_map(map), free(line), false);
		ft_strlcpy(map[i], line, ft_strlen(line) + 1);
		free(line);
		i++;
	}
	map[i] = (char *)0;
	close(fd);
	return (true);
}

bool	is_map_rectangular(char **map)
{
	int		i;
	int		str_len;

	i = 0;
	str_len = ft_strlen(map[0]);
	while(map[i])
		if ((ft_strlen(map[i++]) != str_len) || str_len < 3)
			return (free_map(map), false);
	return (true);
}

bool	is_map_closed(char **map)
{
	return (true);
}

bool	is_map_solvable(char **map)
{
	return (true);
}
