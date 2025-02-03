/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:17:40 by daxferna          #+#    #+#             */
/*   Updated: 2025/02/03 20:49:52 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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

char	**dup_map(t_map game)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (game.height + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (game.map[i])
	{
		new_map[i] = ft_strdup(game.map[i]);
		if (!new_map[i])
			return (free_map(new_map), NULL);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

bool	is_map_rectangular(t_map *game)
{
	int		i;

	i = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) - 1 != game->width)
			return (false);
		i++;
	}
	return (true);
}

bool	is_map_closed(t_map *game)
{
	int	i;

	i = 0;
	if (!is_wall(game->map[0]))
		return (false);
	if (!is_wall(game->map[game->height - 1]))
		return (false);
	while (game->map[i])
	{
		if (game->map[i][0] != WALL)
			return (false);
		if (game->map[i][game->width - 1] != WALL)
			return (false);
		i++;
	}
	return (true);
}

void	dfs(char **map, int pos_y, int pos_x, int *c, int *e)
{
	if (map[pos_x][pos_y] == '1' || map[pos_x][pos_y] == '#')
		return ;
	if (map[pos_x][pos_y] == 'C')
		(*c)++;
	if (map[pos_x][pos_y] == 'E')
		(*e)++;
	map[pos_x][pos_y] = '#';
	dfs(map, pos_y + 1, pos_x, c, e);
	dfs(map, pos_y - 1, pos_x, c, e);
	dfs(map, pos_y, pos_x + 1, c, e);
	dfs(map, pos_y, pos_x - 1, c, e);
}
