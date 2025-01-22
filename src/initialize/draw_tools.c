/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:30:38 by daxferna          #+#    #+#             */
/*   Updated: 2025/01/22 00:05:02 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	put_tile(char *path, mlx_t *window, int row, int col)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	img = mlx_texture_to_image(window, texture);
	mlx_image_to_window(window, img, IMGSIZE * col, IMGSIZE * row);
}

void	put_border(mlx_t *window, int width, int height, int row, int col)
{
	if ((row == 0 || row == height - 1) && (col != 0 && col != width - 1))
	{
		put_tile(WALL_LEFT_IMG, window, row, col);
		put_tile(WALL_RIGHT_IMG, window, row, col);
	}
	else if ((col == 0 || col == width - 1) && (row != 0 && row != height - 1))
	{
		put_tile(WALL_TOP_IMG, window, row, col);
		put_tile(WALL_BOTTOM_IMG, window, row, col);
	}
	else 
	{
		if (row == 0)
			put_tile(WALL_BOTTOM_IMG, window, row, col);
		if (row == height - 1)
			put_tile(WALL_TOP_IMG, window, row, col);
		if (col == 0)
			put_tile(WALL_RIGHT_IMG, window, row, col);
		if (col == width - 1)
			put_tile(WALL_LEFT_IMG, window, row, col);
	}
	
}

void	which_fence(mlx_t *window, t_map game_map, int i, int j)
{
	put_tile(WALL_CENTER_IMG, window, i, j);
	if (i == 0 || j == 0 || i == game_map.width - 1 || j == game_map.height - 1)
		put_border(window, game_map.width, game_map.height, i, j);
	else
	{
		if (game_map.map[i-1][j] == WALL)
			put_tile(WALL_TOP_IMG, window, i, j);
		if (game_map.map[i][j-1] == WALL)
			put_tile(WALL_BOTTOM_IMG, window, i, j);
		if (game_map.map[i][j+1] == WALL)
			put_tile(WALL_LEFT_IMG, window, i, j);
		if (game_map.map[i+1][j] == WALL)
			put_tile(WALL_RIGHT_IMG, window, i, j);
	}
}
