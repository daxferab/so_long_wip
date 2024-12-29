/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:17:40 by daxferna          #+#    #+#             */
/*   Updated: 2024/12/29 20:12:01 by daxferna         ###   ########.fr       */
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

bool	is_map_rectangular(t_map *game_map)
{
	int		i;

	i = 0;
	while (game_map->map[i])
	{
		if (ft_strlen(game_map->map[i]) - 1 != game_map->width)
			return (false);
		i++;
	}
	return (true);
}

bool	is_map_closed(t_map *game_map)
{
	int		i;

	i = 0;
	if (!is_wall(game_map->map[0]))
		return (false);
	if (!is_wall(game_map->map[game_map->height - 1]))
		return (false);
	while (game_map->map[i])
	{
		if (game_map->map[i][0] != WALL)
			return (false);
		if (game_map->map[i][game_map->width - 1] != WALL)
			return (false);
		i++;
	}
	return (true);
}

bool	all_chars_connected(t_map	*game_map)
{
	return (true);
}

bool	is_map_solvable(t_map *game_map)
{
	if (!is_map_rectangular(game_map))
		return (false);
	if (!is_map_closed(game_map))
		return (false);
	if (!has_only_valid_chars(game_map))
		return (false);
	if (!has_exit_and_player(game_map))
		return (false);
	if (!has_collectibles(game_map))
		return (false);
	if (!all_chars_connected(game_map))
		return (false);
	return (true);
}
