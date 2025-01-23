/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:39:03 by daxferna          #+#    #+#             */
/*   Updated: 2025/01/23 01:49:15 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "lib/libft/libft.h"
# include "lib/mlx/include/MLX42/MLX42.h"
# include <stdbool.h>
# include <stdlib.h>
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define IMGSIZE 128
# define CLOSED_EXIT_IMG "textures/closedExit.png"
# define COLLECTIBLE_IMG "textures/collectible.png"
# define FLOOR_IMG "textures/floor.png"
# define OPEN_EXIT_IMG "textures/openExit.png"
# define PLAYER_IMG "textures/player.png"
# define WALL_BOTTOM_IMG "textures/wallBottom.png"
# define WALL_CENTER_IMG "textures/wallCenter.png"
# define WALL_RIGHT_IMG "textures/wallRight.png"
# define WALL_TOP_IMG "textures/wallTop.png"
# define WALL_LEFT_IMG "textures/wallLeft.png"

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		collectibles;
	int		exit;
	int		player_x;
	int		player_y;
}	t_map;

// errors.c
void	error(int errno);

// free_map.c
void	free_map(char **map);

/***************************** PARSE *****************************/
// arg_validation.c
bool	is_ber_extension(char	*archive);
void	validate_arg(char *arg, t_map *game_map);

// map_utils.c
bool	is_wall(char *map_line);
bool	has_exit_and_player(t_map *game_map);
bool	has_collectibles(t_map *game_map);
bool	has_only_valid_chars(t_map *game_map);
bool	is_valid_char(char c);

//map_utils2.c
int		count_fd_lines(int fd);
char	**dup_map(t_map game_map);
bool	is_map_rectangular(t_map *game_map);
bool	is_map_closed(t_map *game_map);
void	dfs(char **map, int	pos_x, int pos_y, int *c, int *e);

// map_validation.c
bool	map_to_matrix(int fd, t_map *game_map);
bool	is_map_solvable(t_map *game_map);
bool	is_map_valid(char	*arg, t_map *game_map);

/*************************** INITIALIZE **************************/
// draw_tools.c
void	put_tile(char *path, mlx_t *window, int row, int col);
void	put_border(mlx_t *window, int width, int height, int row, int col);
void	which_fence(mlx_t *window, t_map game_map, int i, int j);

// draw_map.c
void	draw_floor(mlx_t *window, int width, int height);
void	draw_walls(mlx_t *window, t_map game_map);
void	draw_other_tiles(mlx_t *window, t_map game_map);
void	draw_map(mlx_t *window, t_map game_map);

// init_map.c
mlx_t	*init_map(t_map game_map);

#endif
