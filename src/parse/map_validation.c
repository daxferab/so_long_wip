/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:17:07 by daxferna          #+#    #+#             */
/*   Updated: 2025/01/14 20:01:48 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool	map_to_matrix(int fd, t_map *game_map)
{
	char	*line;
	int		i;

	game_map->map = malloc((sizeof(char *) * (game_map->height + 1)));
	if (!game_map->map)
		return (false);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		game_map->map[i] = ft_strdup(line);
		if (!(game_map->map)[i])
			return (free_map(game_map->map), free(line), false);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	(game_map->map)[i] = NULL;
	game_map->width = ft_strlen(game_map->map[0]) - 1;
	return (true);
}

bool	is_map_solvable(t_map *game_map)
{
	int		c;
	int		e;
	char	**validation_map;

	c = 0;
	e = 0;
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
	validation_map = dup_map(*game_map);
	dfs(validation_map, game_map->player_x, game_map->player_y, &c, &e);
	free_map(validation_map);
	if (c != game_map->collectibles || e != 1)
		return (false);
	return (true);
}

bool	is_map_valid(char	*arg, t_map	*game_map)
{
	int		fd;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (false);
	game_map->height = count_fd_lines(fd);
	close(fd);
	if (game_map->height < 3)
		return (false);
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (false);
	if (!map_to_matrix(fd, game_map))
		return (close(fd), false);
	close(fd);
	if (!game_map->map)
		return (false);
	if (!is_map_solvable(game_map))
		return (free_map(game_map->map), false);
	return (true);
}
