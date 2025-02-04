/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:17:07 by daxferna          #+#    #+#             */
/*   Updated: 2025/02/04 20:29:55 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool	map_to_matrix(int fd, t_map *game)
{
	char	*line;
	int		i;

	game->map = malloc((sizeof(char *) * (game->height + 1)));
	if (!game->map)
		return (false);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		game->map[i] = ft_strdup(line);
		if (!(game->map)[i])
			return (free_map(game->map), free(line), false);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	(game->map)[i] = NULL;
	game->width = ft_strlen(game->map[0]) - 1;
	return (true);
}

bool	is_map_solvable(t_map *game)
{
	int		*ce;
	char	**validation_map;

	ce = malloc(sizeof(int) * 2);
	if (!ce)
		return (false);
	ce[0] = 0;
	ce[1] = 0;
	if (!is_map_rectangular(game))
		return (false);
	if (!is_map_closed(game))
		return (false);
	if (!has_only_valid_chars(game))
		return (false);
	if (!has_exit_and_player(game))
		return (false);
	if (!has_collectibles(game))
		return (false);
	validation_map = dup_map(*game);
	dfs(validation_map, game->player_x, game->player_y, &ce);
	free_map(validation_map);
	if (ce[0] != game->num_collectibles || ce[1] != 1)
		return (false);
	return (true);
}

bool	is_map_valid(char	*arg, t_map	*game)
{
	int		fd;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (false);
	game->height = count_fd_lines(fd);
	close(fd);
	if (game->height < 3)
		return (false);
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (false);
	if (!map_to_matrix(fd, game))
		return (close(fd), false);
	close(fd);
	if (!game->map)
		return (false);
	if (!is_map_solvable(game))
		return (free_map(game->map), false);
	return (true);
}
