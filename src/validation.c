/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 22:16:45 by daxferna          #+#    #+#             */
/*   Updated: 2024/12/25 19:14:47 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	is_map_valid(char	*arg)
{
	int		fd;
	char	**map;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (false);
	map = map_to_matrix(fd);
	close(fd);
	if (!map)
		return (false);
	if (!is_map_closed(map) || !is_map_solvable(map))
		return (false);
	return(true);
}

bool	is_ber_extension(char	*archive)
{
	char	*tmp;
	int		archive_len;

	tmp = archive;
	archive_len = ft_strlen(archive);
	if (archive_len < 4)
		return (false);
	if (ft_strncmp(archive + archive_len - 4, ".ber", 4) != 0)
		return (false);
	return (true);
}

void	validate_arg(char	*arg)
{
	if (!is_ber_extension(arg))
		error(2);
	if (!is_map_valid(arg))
		error(3);
}
