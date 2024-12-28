/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:17:07 by daxferna          #+#    #+#             */
/*   Updated: 2024/12/28 05:38:46 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	map_to_matrix(int fd, char ***map, int map_lines)
{
	char	*line;
	int		i;
	int		line_len;

	*map = malloc((sizeof(char *) * (map_lines + 1)));
	if (!*map)
		return (false);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_len = ft_strlen(line);
		(*map)[i] = malloc(line_len + 1);
		if (!(*map)[i])
			return (free_map(*map), free(line), false);
		ft_strlcpy((*map)[i++], line, line_len + 1);
		free(line);
		line = get_next_line(fd);
	}
	(*map)[i] = NULL;
	return (true);
}

bool	is_map_rectangular(char **map)
{
	int		i;
	int		str_len;

	i = 0;
	str_len = ft_strlen(map[i]);
	while(map[i])
	{
		if ((ft_strlen(map[i++]) != str_len) || str_len < 3)
			return (free_map(map), false);
	}
	i++;
	if (i < 3)
		return (free_map(map), false);
	return (true);
}

bool	is_map_closed(char **map)
{
	int		width;
	int		height;
	int		i;

	width = ft_strlen(map[0]) - 1;
	height = get_map_height(map);
	i = 0;
	if (!is_wall(map[0]) || !is_wall(map[height - 1]))
		return (false);
	while (map[i])
	{
		if (map[i][0] != WALL || map[i][width - 1] != WALL)
			return (false);
		i++;
	}
	return (true);
}

bool	is_map_solvable(char **map)
{
	if (!has_mandatory_elements(map))
		return (false);
	return (true);
}
