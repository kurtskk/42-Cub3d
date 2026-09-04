/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:18:05 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:18:17 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	render_loop(t_cub *cub)
{
	process_keys(cub);
	update_door_animation(cub);
	raycast(cub);
	render_sprites(cub);
	render_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->screen.img, 0, 0);
	return (0);
}
