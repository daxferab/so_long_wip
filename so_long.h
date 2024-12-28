/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:39:03 by daxferna          #+#    #+#             */
/*   Updated: 2024/12/28 05:38:21 by daxferna         ###   ########.fr       */
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

// errors.c
void	error(int errno);

// free_map.c
void	free_map(char **map);

// map_validation.c
bool	map_to_matrix(int fd, char ***map, int map_lines);
bool	is_map_rectangular(char **map);
bool	is_map_closed(char **map);
bool	is_map_solvable(char **map);

// map_utils.c
int		count_fd_lines(int fd);
int		get_map_height(char **map);
bool	is_wall(char *map_line);
bool	has_mandatory_elements(char	**map);

// validation.c
bool	is_map_valid(char	*arg, char	***map);
bool	is_ber_extension(char	*archive);
void	validate_arg(char *arg, char ***map);

#endif
