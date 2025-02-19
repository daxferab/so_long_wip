/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:17:40 by daxferna          #+#    #+#             */
/*   Updated: 2025/02/19 20:57:46 by daxferna         ###   ########.fr       */
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

void	is_map_rectangular(t_map *game)
{
	int		i;

	i = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) - 1 != game->width)
		{
			free_map(game->map);
			error(6, game);
		}
		i++;
	}
}

void	is_map_closed(t_map *game)
{
	int	i;

	i = 0;
	if (!is_wall(game->map[0]) || !is_wall(game->map[game->height - 1]))
	{
		free_map(game->map);
		error(7, game);
	}
	while (game->map[i])
	{
		if (game->map[i][0] != WALL || game->map[i][game->width - 1] != WALL)
		{
			free_map(game->map);
			error(7, game);
		}
		i++;
	}
}

void	dfs(char **map, int pos_y, int pos_x, int ce[])
{
	if (map[pos_x][pos_y] == '1' || map[pos_x][pos_y] == '#')
		return ;
	if (map[pos_x][pos_y] == 'C')
		ce[0]++;
	if (map[pos_x][pos_y] == 'E')
		ce[1]++;
	map[pos_x][pos_y] = '#';
	dfs(map, pos_y + 1, pos_x, ce);
	dfs(map, pos_y - 1, pos_x, ce);
	dfs(map, pos_y, pos_x + 1, ce);
	dfs(map, pos_y, pos_x - 1, ce);
}
