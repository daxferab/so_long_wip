/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:32:45 by daxferna          #+#    #+#             */
/*   Updated: 2025/01/31 01:18:28 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_map(t_map *game)
{	
	game->window = mlx_init(IMGSIZE * game->width,
			IMGSIZE * game->height, "so_long", false); //FIXME: Depends on map size
	draw_map(game);
}
