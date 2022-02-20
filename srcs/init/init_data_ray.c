/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:07:31 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 11:07:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init3_more(t_recup *recup)
{
	if (recup->ray.raydiry == 0)
		recup->ray.deltadistx = 0;
	else if (recup->ray.raydirx == 0)
		recup->ray.deltadistx = 1;
	else
		recup->ray.deltadistx = sqrt(1 + (recup->ray.raydiry \
				* recup->ray.raydiry) / (recup->ray.raydirx \
				* recup->ray.raydirx));
	if (recup->ray.raydirx == 0)
		recup->ray.deltadisty = 0;
	else if (recup->ray.raydiry == 0)
		recup->ray.deltadisty = 1;
	else
		recup->ray.deltadisty = sqrt(1 + (recup->ray.raydirx \
			* recup->ray.raydirx) / (recup->ray.raydiry * recup->ray.raydiry));
}

void	ft_initialisation3(t_recup *recup)
{
	recup->ray.hit = 0;
	recup->ray.perpwalldist = 0;
	recup->ray.camerax = 2 * recup->ray.x / (double)recup->rx - 1;
	recup->ray.raydirx = recup->ray.dirx + recup->ray.planx \
		* recup->ray.camerax;
	recup->ray.raydiry = recup->ray.diry + recup->ray.plany \
		* recup->ray.camerax;
	recup->ray.mapx = (int)recup->ray.posx;
	recup->ray.mapy = (int)recup->ray.posy;
	recup->ray.movespeed = 0.1;
	recup->ray.rotspeed = 0.033 * 1.8;
	ft_init3_more(recup);
}

