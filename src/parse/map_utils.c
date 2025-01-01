/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 01:56:15 by daxferna          #+#    #+#             */
/*   Updated: 2025/01/01 02:52:14 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool	is_valid_char(char c)
{
	return (c == WALL || c == FLOOR || c == PLAYER
	|| c == COLLECTIBLE || c == EXIT || c == '\n');
}

bool	is_wall(char *map_line)
{
	int	i;

	i = 0;
	while (map_line[i] != '\n')
	{
		if (map_line[i] != WALL)
			return (false);
		i++;
	}
	return (true);
}

bool	has_exit_and_player(t_map *game_map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	game_map->exit = 0;
	player = 0;
	while (game_map->map[i])
	{
		j = 0;
		while (game_map->map[i][j])
		{
			if (game_map->map[i][j] == PLAYER)
			{
				game_map->player_x = j;
				game_map->player_y = i;
				player++;
			}
			if (game_map->map[i][j] == EXIT)
				game_map->exit++;
			j++;
		}
		i++;
	}
	return (player == 1 && game_map->exit == 1);
}

bool	has_collectibles(t_map *game_map)
{
	int	i;
	int	j;

	i = 0;
	game_map->collectibles = 0;
	while (game_map->map[i])
	{
		j = 0;
		while (game_map->map[i][j])
		{
			if (game_map->map[i][j] == COLLECTIBLE)
				game_map->collectibles++;
			j++;
		}
		i++;
	}
	return (game_map->collectibles > 0);
}

bool	has_only_valid_chars(t_map *game_map)
{
	int	i;
	int	j;

	i = 0;
	while (game_map->map[i])
	{
		j = 0;
		while (game_map->map[i][j])
		{
			if (!is_valid_char(game_map->map[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
