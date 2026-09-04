/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:21:15 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:21:23 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	validate_parsed_map(t_cub *cub);

int	parse_cub_file(char *file, t_cub *cub)
{
	int		fd;
	t_list	*map_lines;

	map_lines = NULL;
	init_map(&cub->map);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd(ERR_FILE, 2), 1);
	if (parse_file_lines(fd, cub, &map_lines))
		return (close(fd), cleanup_parse_error(cub, &map_lines));
	close(fd);
	get_next_line(-1);
	if (!cub->map.grid)
	{
		ft_putstr_fd("Error\nNo map found\n", 2);
		return (cleanup_parse_error(cub, &map_lines));
	}
	ft_lstclear(&map_lines, free);
	return (validate_parsed_map(cub));
}

static int	validate_parsed_map(t_cub *cub)
{
	if (validate_map(&cub->map))
		return (cleanup_cub_return(cub));
	if (parse_doors(&cub->map))
		return (cleanup_cub_return(cub));
	if (parse_sprites(&cub->map))
		return (cleanup_cub_return(cub));
	if (parse_exit(&cub->map))
		return (cleanup_cub_return(cub));
	return (0);
}
