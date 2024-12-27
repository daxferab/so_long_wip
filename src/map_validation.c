/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:17:07 by daxferna          #+#    #+#             */
/*   Updated: 2024/12/27 04:39:32 by daxferna         ###   ########.fr       */
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
	return (true);
}

bool	is_map_solvable(char **map)
{
	return (true);
}
