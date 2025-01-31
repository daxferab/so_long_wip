/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:10:03 by daxferna          #+#    #+#             */
/*   Updated: 2025/01/31 01:24:23 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	draw_floor(t_map game)
{
	int i;
	int j;

	i = 0;
	while (i < game.height)
	{
		j = 0;
		while (j < game.width)
		{
			put_tile(FLOOR_IMG, game.window, i, j, 0);
			j++;
		}
		i++;
	}
}

void	draw_walls(t_map game)
{
	int i;
	int j;

	i = 0;
	while (i < game.height)
	{
		j = 0;
		while (j < game.width)
		{
			if (game.map[i][j] == WALL)
				which_fence(game.window, game, i, j);
			j++;
		}
		i++;
	}
}

void	draw_other_tiles(t_map *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == PLAYER)
				game->player = put_tile(PLAYER_IMG, game->window, i, j, 8);
			else if (game->map[i][j] == COLLECTIBLE)
				put_tile(COLLECT_IMG, game->window, i, j, 5);
			else if (game->map[i][j] == EXIT)
				put_tile(CLOSED_EXIT_IMG, game->window, i, j, 5);
			j++;
		}
		i++;
	}
}

void	draw_map(t_map *game)
{
	draw_floor(*game);
	draw_walls(*game);
	draw_other_tiles(game);
}
