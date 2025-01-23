/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:32:45 by daxferna          #+#    #+#             */
/*   Updated: 2025/01/23 02:46:44 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

mlx_t	*init_map(t_map game_map)
{
	mlx_t	*window;
	
	window = mlx_init(IMGSIZE * game_map.width,\
	IMGSIZE * game_map.height, "so_long", false); //FIXME: Depends on map size
	draw_map(window, game_map);
	mlx_loop(window);
	return (window);
}
