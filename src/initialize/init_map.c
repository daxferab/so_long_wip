/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:32:45 by daxferna          #+#    #+#             */
/*   Updated: 2025/02/26 20:37:06 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	min_num(t_map *game, int screen_w, int screen_h)
{
	if (screen_w / game->width > screen_h / game->height)
		return (screen_h / game->height);
	else
		return (screen_w / game->width);
}

static void	create_window(t_map *game)
{
	int	screen_w;
	int	screen_h;
	int	size;

	mlx_set_setting(MLX_HEADLESS, true);
	game->window = mlx_init(1, 1, "", false);
	mlx_get_monitor_size(0, &screen_w, &screen_h);
	mlx_terminate(game->window);
	mlx_set_setting(MLX_HEADLESS, false);
	size = min_num(game, screen_w, screen_h) - 10;
	game->window = mlx_init(game->width * (size),
			game->height * (size), "so_long", false);
	if (!game->window)
		error(1, game);
}

void	init_map(t_map *game)
{
	create_window(game);
	draw_map(game);
}
