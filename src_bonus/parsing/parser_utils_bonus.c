/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:21:17 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:21:20 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	handle_parse_error(int fd, char *line);
static int	handle_map_start(int fd, char *line, t_cub *cub,
				t_list **map_lines);

int	process_line(int fd, char *line, t_cub *cub, t_list **map_lines)
{
	int	ret;

	ret = parse_line(line, cub);
	if (ret == 1)
		return (handle_parse_error(fd, line));
	if (ret == 2)
	{
		ret = handle_map_start(fd, line, cub, map_lines);
		if (ret == 1)
		{
			get_next_line(-1);
			return (1);
		}
		return (2);
	}
	return (0);
}

int	parse_file_lines(int fd, t_cub *cub, t_list **map_lines)
{
	char	*line;
	int		ret;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ret = process_line(fd, line, cub, map_lines);
		if (ret == 1)
			return (1);
		if (ret == 2)
			break ;
		free(line);
	}
	return (0);
}

static int	handle_map_start(int fd, char *line, t_cub *cub,
	t_list **map_lines)
{
	if (read_map(fd, line, cub, map_lines))
	{
		free(line);
		close(fd);
		return (1);
	}
	free(line);
	return (2);
}

static int	handle_parse_error(int fd, char *line)
{
	free(line);
	get_next_line(-1);
	close(fd);
	return (1);
}
