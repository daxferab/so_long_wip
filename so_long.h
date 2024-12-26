/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:39:03 by daxferna          #+#    #+#             */
/*   Updated: 2024/12/26 03:25:00 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>

// errors.c
void	error(int errno);

// free_map.c
void	free_map(char **map);

// map_validation.c
bool	map_to_matrix(int fd, char **map, char *arg);
bool	is_map_rectangular(char **map);
bool	is_map_closed(char **map);
bool	is_map_solvable(char **map);

// utils.c
int		malloc_map_lines(int fd, char **map);

// validation.c
bool	is_map_valid(char	*arg);
bool	is_ber_extension(char	*archive);
void	validate_arg(char *arg);

#endif