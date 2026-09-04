/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_helper_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:16:41 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:18:52 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	calc_wall_x(t_cub *cub, t_ray *ray);
static void	calc_perp_dist_and_height(t_ray *ray);
static void	calc_texture_step(t_cub *cub, t_ray *ray);

void	calc_wall_height(t_cub *cub, t_ray *ray)
{
	calc_perp_dist_and_height(ray);
	calc_wall_x(cub, ray);
	select_texture(cub, ray);
	calc_texture_step(cub, ray);
}

void	init_ray(t_cub *cub, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->ray_dir_x = cub->player.dir_x + cub->player.plane_x * ray->camera_x;
	ray->ray_dir_y = cub->player.dir_y + cub->player.plane_y * ray->camera_x;
	ray->map_x = (int)cub->player.pos_x;
	ray->map_y = (int)cub->player.pos_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

static void	calc_perp_dist_and_height(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

static void	calc_wall_x(t_cub *cub, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = cub->player.pos_y
			+ ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = cub->player.pos_x
			+ ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

static void	calc_texture_step(t_cub *cub, t_ray *ray)
{
	ray->step = 1.0 * cub->map.textures[ray->tex_num].height
		/ ray->line_height;
	ray->tex_pos = (ray->draw_start - WIN_HEIGHT / 2
			+ ray->line_height / 2) * ray->step;
}
