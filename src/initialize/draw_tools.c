/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:30:38 by daxferna          #+#    #+#             */
/*   Updated: 2025/02/11 00:29:46 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

mlx_image_t	*put_tile(char *path, t_map *game, int row, int col, int depth)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
		error(4, game);
	img = mlx_texture_to_image(game->window, texture);
	mlx_delete_texture(texture);
	mlx_resize_image(img, IMGSIZE, IMGSIZE);
	if (!img)
		error(4, game);
	mlx_image_to_window(game->window, img, IMGSIZE * col, IMGSIZE * row);
	mlx_set_instance_depth(img->instances, depth);
	return (img);
}

static bool	has_wall_near(t_map game, int row, int col)
{
	if (row < 0 || row >= game.height || col < 0 || col >= game.width)
		return (false);
	if (game.map[row][col] == WALL)
		return (true);
	return (false);
}

void	which_fence(t_map game, int i, int j)
{
	put_tile(WALL_CENTER_IMG, &game, i, j, 1);
	if (has_wall_near(game, i - 1, j))
		put_tile(WALL_TOP_IMG, &game, i, j, 2);
	if (has_wall_near(game, i, j - 1))
		put_tile(WALL_LEFT_IMG, &game, i, j, 3);
	if (has_wall_near(game, i, j + 1))
		put_tile(WALL_RIGHT_IMG, &game, i, j, 4);
	if (has_wall_near(game, i + 1, j))
		put_tile(WALL_BOTTOM_IMG, &game, i, j, 5);
}
