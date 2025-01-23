/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:10:03 by daxferna          #+#    #+#             */
/*   Updated: 2025/01/23 15:22:02 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	draw_floor(mlx_t *window, t_map game_map)
{
	int i;
	int j;

	i = 0;
	while (i < game_map.height)
	{
		j = 0;
		while (j < game_map.width)
		{
			put_tile(FLOOR_IMG, window, i, j);
			j++;
		}
		i++;
	}
}

void	draw_walls(mlx_t *window, t_map game_map)
{
	int i;
	int j;

	i = 0;
	while (i < game_map.height)
	{
		j = 0;
		while (j < game_map.width)
		{
			if (game_map.map[i][j] == WALL)
				which_fence(window, game_map, i, j);
			j++;
		}
		i++;
	}
}

void	draw_other_tiles(mlx_t *window, t_map game_map)
{
	int i;
	int j;

	i = 0;
	while (i < game_map.height)
	{
		j = 0;
		while (j < game_map.width)
		{
			if (game_map.map[i][j] == PLAYER)
				put_tile(PLAYER_IMG, window, i, j);
			else if (game_map.map[i][j] == COLLECTIBLE)
				put_tile(COLLECTIBLE_IMG, window, i, j);
			else if (game_map.map[i][j] == EXIT)
				put_tile(CLOSED_EXIT_IMG, window, i, j);
			j++;
		}
		i++;
	}
}

void	draw_map(mlx_t *window, t_map game_map)
{
	draw_floor(window, game_map);
	draw_walls(window, game_map);
	draw_other_tiles(window, game_map);
}
