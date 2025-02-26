/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:17:07 by daxferna          #+#    #+#             */
/*   Updated: 2025/02/26 20:03:33 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static bool	map_to_matrix(int fd, t_map *game)
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

static void	is_map_solvable(t_map *game)
{
	int		ce[2];
	char	**validation_map;

	is_map_rectangular(game);
	is_map_closed(game);
	has_only_valid_chars(game);
	if (!has_exit_and_player(game) || !has_collectibles(game))
	{
		free_map(game->map);
		error(4, game);
	}
	validation_map = dup_map(*game);
	ce[0] = 0;
	ce[1] = 0;
	dfs(validation_map, game->pla_x, game->pla_y, ce);
	free_map(validation_map);
	if (ce[0] != game->num_collectibles || ce[1] != 1)
	{
		free_map(game->map);
		error(8, game);
	}
}

void	is_map_valid(char	*arg, t_map	*game)
{
	int		fd;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
		error(1, game);
	game->height = count_fd_lines(fd);
	close(fd);
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		error(1, game);
	if (!map_to_matrix(fd, game))
	{
		close(fd);
		error(1, game);
	}
	close(fd);
	if (!game->map)
		error(1, game);
	is_map_solvable(game);
}
