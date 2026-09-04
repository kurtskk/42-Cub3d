/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_helper_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:10:11 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:10:42 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	cleanup_map_lines(t_list **map_lines)
{
	if (map_lines && *map_lines)
	{
		ft_lstclear(map_lines, free);
		*map_lines = NULL;
	}
}

int	cleanup_parse_error(t_cub *cub, t_list **map_lines)
{
	cleanup_map_lines(map_lines);
	return (cleanup_cub_return(cub));
}

int	is_texture_image(void *img, t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (img == cub->map.textures[i].img)
			return (1);
		i++;
	}
	return (0);
}

int	was_already_freed(void *img, t_cub *cub, int current_index)
{
	int	j;

	j = 0;
	while (j < current_index && j < 9)
	{
		if (cub->map.sprite_frames[j].img == img)
			return (1);
		j++;
	}
	return (0);
}
