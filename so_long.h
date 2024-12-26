/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:39:03 by daxferna          #+#    #+#             */
/*   Updated: 2024/12/26 01:07:47 by daxferna         ###   ########.fr       */
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
char	**map_to_matrix(int fd);
bool	is_map_closed(char **map);
bool	is_map_solvable(char **map);

// validation.c
bool	is_map_valid(char	*arg);
bool	is_ber_extension(char	*archive);
void	validate_arg(char *arg);

#endif