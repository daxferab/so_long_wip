/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:10:03 by daxferna          #+#    #+#             */
/*   Updated: 2025/02/18 22:38:52 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	draw_floor(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	game->depth = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			put_tile(FLOOR_IMG, game, i, j);
			j++;
		}
		i++;
	}
}

static void	draw_walls(t_map game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game.height)
	{
		j = 0;
		while (j < game.width)
		{
			if (game.map[i][j] == WALL)
				which_fence(&game, i, j);
			j++;
		}
		i++;
	}
}

static void	draw_other_tiles(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			game->depth = 5;
			if (game->map[i][j] == PLAYER)
			{
				game->depth = 8;
				game->player = put_tile(PLAYER_IMG, game, i, j);
			}
			else if (game->map[i][j] == COLLECTIBLE)
				put_tile(COLLECT_IMG, game, i, j);
			else if (game->map[i][j] == EXIT)
				put_tile(CLOSED_EXIT_IMG, game, i, j);
			j++;
		}
		i++;
	}
}

void	draw_map(t_map *game)
{
	draw_floor(game);
	draw_walls(*game);
	draw_other_tiles(game);
}
