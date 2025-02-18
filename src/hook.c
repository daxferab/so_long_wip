/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:11:29 by daxferna          #+#    #+#             */
/*   Updated: 2025/02/18 22:25:08 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	move_player(t_map *game, int key)
{
	if (key == MLX_KEY_UP && game->map[game->pla_y - 1][game->pla_x] != WALL)
	{
		game->pla_y -= 1;
		game->player->instances[0].y -= game->tile_size;
		return (true);
	}
	if (key == MLX_KEY_DOWN && game->map[game->pla_y + 1][game->pla_x] != WALL)
	{
		game->pla_y += 1;
		game->player->instances[0].y += game->tile_size;
		return (true);
	}
	if (key == MLX_KEY_LEFT && game->map[game->pla_y][game->pla_x - 1] != WALL)
	{
		game->pla_x -= 1;
		game->player->instances[0].x -= game->tile_size;
		return (true);
	}
	if (key == MLX_KEY_RIGHT && game->map[game->pla_y][game->pla_x + 1] != WALL)
	{
		game->pla_x += 1;
		game->player->instances[0].x += game->tile_size;
		return (true);
	}
	return (false);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_map	*game;
	bool	moved;

	game = (t_map *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		free_game(game);
		exit(0);
	}
	moved = false;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		moved = move_player(game, MLX_KEY_UP);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		moved = move_player(game, MLX_KEY_DOWN);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		moved = move_player(game, MLX_KEY_LEFT);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		moved = move_player(game, MLX_KEY_RIGHT);
	if (moved)
	{
		game->movements++;
		ft_printf("Movements: %d\n", game->movements);
	}
}

void	loop_hook(void *param)
{
	t_map	*game;

	game = (t_map *)param;
	if (game->map[game->pla_y][game->pla_x] == COLLECTIBLE)
	{
		game->map[game->pla_y][game->pla_x] = FLOOR;
		put_tile(FLOOR_IMG, game, game->pla_y, game->pla_x, 6);
		put_tile(COLLECTED_IMG, game, game->pla_y, game->pla_x, 7);
		game->num_collectibles--;
	}
	if (game->num_collectibles == 0)
	{
		put_tile(FLOOR_IMG, game, game->exit_y, game->exit_x, 6);
		put_tile(OPEN_EXIT_IMG, game, game->exit_y, game->exit_x, 7);
		if (game->map[game->pla_y][game->pla_x] == EXIT)
		{
			free_game(game);
			exit(0);
		}
	}
}
