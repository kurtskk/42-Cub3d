/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:06:05 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:06:11 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	raycast(t_cub *cub)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(cub, &ray, x);
		calc_step(cub, &ray);
		perform_dda(cub, &ray);
		calc_wall_height(cub, &ray);
		draw_column(cub, x, &ray);
		x++;
	}
	return (0);
}
