/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:01:02 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:01:13 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
