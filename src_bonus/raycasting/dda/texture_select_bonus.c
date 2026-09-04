/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_select_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:16:44 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:18:49 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	select_wall_texture(t_ray *ray);
static int	get_door_anim_frame(t_cub *cub, int map_x, int map_y);

void	select_texture(t_cub *cub, t_ray *ray)
{
	char	cell;

	cell = cub->map.grid[ray->map_y][ray->map_x];
	if (cell == 'D')
		ray->tex_num = get_door_anim_frame(cub, ray->map_x, ray->map_y);
	else
		select_wall_texture(ray);
	ray->tex_x = (int)(ray->wall_x
			* (double)cub->map.textures[ray->tex_num].width);
	adjust_texture_x(cub, ray);
}

void	adjust_texture_x(t_cub *cub, t_ray *ray)
{
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->tex_x = cub->map.textures[ray->tex_num].width
			- ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->tex_x = cub->map.textures[ray->tex_num].width
			- ray->tex_x - 1;
}

static void	select_wall_texture(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			ray->tex_num = 3;
		else
			ray->tex_num = 2;
	}
	else
	{
		if (ray->ray_dir_y > 0)
			ray->tex_num = 1;
		else
			ray->tex_num = 0;
	}
}

static int	get_door_anim_frame(t_cub *cub, int map_x, int map_y)
{
	int	i;

	i = 0;
	while (i < cub->map.num_doors)
	{
		if (cub->map.doors[i].x == map_x && cub->map.doors[i].y == map_y)
			return (cub->map.doors[i].anim_frame);
		i++;
	}
	return (0);
}
