/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:16:45 by daxferna          #+#    #+#             */
/*   Updated: 2024/12/27 04:37:52 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	is_map_valid(char	*arg, char	***map)
{
	int		fd;
	int		map_lines;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (false);
	map_lines = count_fd_lines(fd);
	close(fd);
	if (map_lines < 3)
		return (false);
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (false);
	if (!map_to_matrix(fd, map, map_lines))
		return (close(fd), false);
	close(fd);
	if (!(*map))
		return (false);
	if (!is_map_rectangular(*map) || !is_map_closed(*map) || !is_map_solvable(*map))
		return (free_map(*map), false);
	return(true);
}

bool	is_ber_extension(char	*archive)
{
	int		archive_len;

	archive_len = ft_strlen(archive);
	if (archive_len < 4)
		return (false);
	if (ft_strncmp(archive + archive_len - 4, ".ber", 4) != 0)
		return (false);
	return (true);
}

void	validate_arg(char	*arg, char	***map)
{
	if (!is_ber_extension(arg))
		error(2);
	if (!is_map_valid(arg, map))
		error(3);
}
