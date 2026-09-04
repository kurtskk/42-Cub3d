/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:07:12 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:07:31 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_loop(t_cub *cub)
{
	process_keys(cub);
	raycast(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->screen.img, 0, 0);
	return (0);
}
