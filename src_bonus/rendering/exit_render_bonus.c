/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_render_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:17:58 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:18:26 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	render_exit(t_cub *cub)
{
	t_sprite_calc	sc;
	t_sprite_draw	sd;
	t_img			*tex;

	calc_sprite_transform(cub, &sc, &cub->map.exit_pos);
	if (sc.transform_y > 0)
	{
		calc_sprite_screen(&sc, &sd);
		sd.depth = sc.transform_y;
		tex = &cub->map.sprite_frames[8];
		draw_sprite(cub, &sd, tex);
	}
}
