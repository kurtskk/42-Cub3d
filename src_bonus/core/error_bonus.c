/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:10:25 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:10:37 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	error_exit(char *msg)
{
	ft_putstr_fd(msg, 2);
}

void	error_exit_cleanup(t_cub *cub, char *msg)
{
	ft_putstr_fd(msg, 2);
	cleanup_cub(cub);
	exit(1);
}
