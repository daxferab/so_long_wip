/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:30:38 by daxferna          #+#    #+#             */
/*   Updated: 2025/01/23 16:42:59 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	put_tile(char *path, mlx_t *window, int row, int col)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	img = mlx_texture_to_image(window, texture);
	mlx_resize_image(img, IMGSIZE, IMGSIZE);
	mlx_image_to_window(window, img, IMGSIZE * col, IMGSIZE * row);
	//TODO: set depth
}

bool	is_corner(int row, int col, t_map game_map)
{
	if ((row == 0 && col == 0) || (row == 0 && col == game_map.width - 1))
		return (true);
	if ((row == game_map.height - 1 && col == 0) || (row == game_map.height - 1 && col == game_map.width - 1))
		return (true);
	return (false);
}

void	put_corner(mlx_t *window, t_map game_map, int row, int col)
{
	if (row == 0)
		put_tile(WALL_BOTTOM_IMG, window, row, col);
	if (row == game_map.height - 1)
		put_tile(WALL_TOP_IMG, window, row, col);
	if (col == 0)
		put_tile(WALL_RIGHT_IMG, window, row, col);
	if (col == game_map.width - 1)
		put_tile(WALL_LEFT_IMG, window, row, col);
}

void	put_border(mlx_t *window, t_map game_map, int row, int col)
{
	if (is_corner(row, col, game_map))
		return (put_corner(window, game_map, row, col));	
	if (row == 0 || row == game_map.height - 1)
		put_tile(WALL_LEFT_IMG, window, row, col);
	if (row == 0 || row == game_map.height - 1)
		put_tile(WALL_RIGHT_IMG, window, row, col);
	if (col == 0 || col == game_map.width - 1)
		put_tile(WALL_TOP_IMG, window, row, col);
	if (col == 0 || col == game_map.width - 1)
		put_tile(WALL_BOTTOM_IMG, window, row, col);
	if (row == 0)
		if (game_map.map[row+1][col] == WALL)
			put_tile(WALL_BOTTOM_IMG, window, row, col);
	if (row == game_map.height - 1)
		if (game_map.map[row-1][col] == WALL)
			put_tile(WALL_TOP_IMG, window, row, col);
	if (col == 0)
		if (game_map.map[row][col+1] == WALL)
			put_tile(WALL_RIGHT_IMG, window, row, col);
	if (col == game_map.width - 1)
		if (game_map.map[row][col-1] == WALL)
			put_tile(WALL_LEFT_IMG, window, row, col);
}

void	which_fence(mlx_t *window, t_map game_map, int i, int j)
{
	put_tile(WALL_CENTER_IMG, window, i, j);
	if (i == 0 || j == 0 || i == game_map.height - 1 || j == game_map.width - 1)
		put_border(window, game_map, i, j);
	else
	{
		if (game_map.map[i-1][j] == WALL)
			put_tile(WALL_TOP_IMG, window, i, j);
		if (game_map.map[i][j-1] == WALL)
			put_tile(WALL_LEFT_IMG, window, i, j);
		if (game_map.map[i][j+1] == WALL)
			put_tile(WALL_RIGHT_IMG, window, i, j);
		if (game_map.map[i+1][j] == WALL)
			put_tile(WALL_BOTTOM_IMG, window, i, j);
	}
}
