/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:11:29 by daxferna          #+#    #+#             */
/*   Updated: 2025/02/05 17:29:27 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_player(t_map *game, int key)
{
	if (key == MLX_KEY_UP
		&& game->map[game->player_y - 1][game->player_x] != WALL)
	{
		game->player_y -= 1;
		game->player->instances[0].y -= IMGSIZE;
	}
	if (key == MLX_KEY_DOWN
		&& game->map[game->player_y + 1][game->player_x] != WALL)
	{
		game->player_y += 1;
		game->player->instances[0].y += IMGSIZE;
	}
	if (key == MLX_KEY_LEFT
		&& game->map[game->player_y][game->player_x - 1] != WALL)
	{
		game->player_x -= 1;
		game->player->instances[0].x -= IMGSIZE;
	}
	if (key == MLX_KEY_RIGHT
		&& game->map[game->player_y][game->player_x + 1] != WALL)
	{
		game->player_x += 1;
		game->player->instances[0].x += IMGSIZE;
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_map	*game;

	game = (t_map *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		free_map(game->map);
		exit(0);
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_player(game, MLX_KEY_UP);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_player(game, MLX_KEY_DOWN);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_player(game, MLX_KEY_LEFT);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move_player(game, MLX_KEY_RIGHT);
}

void	loop_hook(void *param)
{
	t_map	*game;

	game = (t_map *)param;
	if (game->map[game->player_y][game->player_x] == COLLECTIBLE)
	{
		game->map[game->player_y][game->player_x] = FLOOR;
		put_tile(FLOOR_IMG, game->window, game->player_y, game->player_x, 6);
		game->num_collectibles--;
	}
	if (game->num_collectibles == 0)
	{
		put_tile(OPEN_EXIT_IMG, game->window, game->exit_y, game->exit_x, 6);
		if (game->map[game->player_y][game->player_x] == EXIT)
		{
			free_map(game->map);
			exit(0);
		}
	}
}
