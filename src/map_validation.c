/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:17:07 by daxferna          #+#    #+#             */
/*   Updated: 2024/12/26 01:21:11 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**map_to_matrix(int fd)
{
	char	**map;
	char	*line;
	int		i;
	int		line_len;

	line = get_next_line(fd);
	if (!line)
		return (0);
	i = 0;
	line_len = ft_strlen(line);
	while (line)
	{
		if (ft_strlen(line) != line_len)
			return (0);
		map[i] = malloc(line_len + 1);
		if (!map[i])
			return (free_map(map), (char **)0);
		ft_strlcpy(map[i], line, line_len + 1);
		line = get_next_line(fd);
		line_len = ft_strlen(line);
		i++;
	}
	return (map);
}

bool	is_map_closed(char **map)
{
	return (true);
}

bool	is_map_solvable(char **map)
{
	return (true);
}
