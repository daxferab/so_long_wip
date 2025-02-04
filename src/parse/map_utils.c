/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 01:56:15 by daxferna          #+#    #+#             */
/*   Updated: 2025/02/04 20:31:58 by daxferna         ###   ########.fr       */
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
	int	row;

	row = 0;
	while (map_line[row] != '\n')
	{
		if (map_line[row] != WALL)
			return (false);
		row++;
	}
	return (true);
}

bool	has_exit_and_player(t_map *game)
{
	int	row;
	int	col;
	int	player;
	int	exit;

	row = 0;
	exit = 0;
	player = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (is_player(row, col, game))
				player++;
			if (is_exit(row, col, game))
				exit++;
			col++;
		}
		row++;
	}
	return (player == 1 && exit == 1);
}

bool	has_collectibles(t_map *game)
{
	int	row;
	int	col;

	row = 0;
	game->num_collectibles = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (game->map[row][col] == COLLECTIBLE)
				game->num_collectibles++;
			col++;
		}
		row++;
	}
	return (game->num_collectibles > 0);
}

bool	has_only_valid_chars(t_map *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (!is_valid_char(game->map[row][col]))
				return (false);
			col++;
		}
		row++;
	}
	return (true);
}
