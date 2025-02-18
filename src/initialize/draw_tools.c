/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:30:38 by daxferna          #+#    #+#             */
/*   Updated: 2025/02/18 22:57:48 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

mlx_image_t	*put_tile(char *path, t_map *game, int row, int col)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
		error(4, game);
	img = mlx_texture_to_image(game->window, texture);
	mlx_delete_texture(texture);
	game->tile_size = (game->window->width / game->width);
	mlx_resize_image(img, game->tile_size, game->tile_size);
	if (!img)
		error(4, game);
	mlx_image_to_window(game->window, img, game->tile_size * col,
		game->tile_size * row);
	mlx_set_instance_depth(img->instances, game->depth);
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

void	which_fence(t_map *game, int i, int j)
{
	game->depth = 1;
	put_tile(WALL_CENTER_IMG, game, i, j);
	if (has_wall_near(*game, i - 1, j))
	{
		game->depth = 2;
		put_tile(WALL_TOP_IMG, game, i, j);
	}
	if (has_wall_near(*game, i, j - 1))
	{
		game->depth = 3;
		put_tile(WALL_LEFT_IMG, game, i, j);
	}
	if (has_wall_near(*game, i, j + 1))
	{
		game->depth = 4;
		put_tile(WALL_RIGHT_IMG, game, i, j);
	}
	if (has_wall_near(*game, i + 1, j))
	{
		game->depth = 5;
		put_tile(WALL_BOTTOM_IMG, game, i, j);
	}
}
