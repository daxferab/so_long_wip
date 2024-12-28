/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:39:03 by daxferna          #+#    #+#             */
/*   Updated: 2024/12/28 21:34:39 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

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

// arg_validation.c
bool	is_ber_extension(char	*archive);
void	validate_arg(char *arg, t_map *game_map);

// errors.c
void	error(int errno);

// free_map.c
void	free_map(char **map);

// map_utils.c
bool	is_wall(char *map_line);
bool	has_exit_and_player(t_map *game_map);
bool	has_collectibles(t_map *game_map);
bool	has_only_valid_chars(t_map *game_map);
bool	is_valid_char(char c);

//map_utils2.c
int		count_fd_lines(int fd);
bool	is_map_rectangular(t_map *game_map);
bool	is_map_closed(t_map *game_map);
bool	is_map_solvable(t_map *game_map);

// map_validation.c
bool	map_to_matrix(int fd, t_map *game_map);
bool	is_map_valid(char	*arg, t_map *game_map);

#endif
