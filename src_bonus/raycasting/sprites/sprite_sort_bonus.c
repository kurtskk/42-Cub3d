/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_sort_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:17:43 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:18:38 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	sort_sprites_dist(t_cub *cub);

void	sort_sprites(t_cub *cub)
{
	int				i;
	int				j;
	t_sprite_pos	tmp;

	sort_sprites_dist(cub);
	i = -1;
	while (++i < cub->map.num_sprites - 1)
	{
		j = i;
		while (++j < cub->map.num_sprites)
		{
			if (cub->map.sprites[i].dist < cub->map.sprites[j].dist)
			{
				tmp = cub->map.sprites[i];
				cub->map.sprites[i] = cub->map.sprites[j];
				cub->map.sprites[j] = tmp;
			}
		}
	}
}

static void	sort_sprites_dist(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->map.num_sprites)
	{
		cub->map.sprites[i].dist = ((cub->player.pos_x - cub->map.sprites[i].x)
				* (cub->player.pos_x - cub->map.sprites[i].x)
				+ (cub->player.pos_y - cub->map.sprites[i].y)
				* (cub->player.pos_y - cub->map.sprites[i].y));
		i++;
	}
}
