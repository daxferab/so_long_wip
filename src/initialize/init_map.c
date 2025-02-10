/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:32:45 by daxferna          #+#    #+#             */
/*   Updated: 2025/02/11 00:26:19 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_map(t_map *game)
{
	game->window = mlx_init(IMGSIZE * game->width,
			IMGSIZE * game->height, "so_long", false);
	if (!game->window)
		error(4, game);
	draw_map(game);
}
