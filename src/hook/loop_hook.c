/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:11:35 by daxferna          #+#    #+#             */
/*   Updated: 2025/01/31 01:23:55 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	loop_hook(void *param)
{
	t_map	*game;

	game = (t_map *)param;
	if (game->map[game->player_y][game->player_x] == COLLECTIBLE)
		put_tile(FLOOR_IMG, game->window, game->player_y, game->player_x, 6);
}
