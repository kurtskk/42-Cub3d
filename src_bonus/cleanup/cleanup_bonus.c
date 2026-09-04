/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:07:49 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:11:50 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	cleanup_cub(t_cub *cub)
{
	if (cub->screen.img)
		mlx_destroy_image(cub->mlx, cub->screen.img);
	if (cub->z_buffer)
		free(cub->z_buffer);
	free_all_textures(cub);
	free_texture_paths(&cub->map);
	free_map_grid(&cub->map);
	if (cub->map.doors)
		free(cub->map.doors);
	if (cub->map.sprites)
		free(cub->map.sprites);
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
	{
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
	}
}

int	cleanup_cub_return(t_cub *cub)
{
	cleanup_cub(cub);
	return (1);
}
