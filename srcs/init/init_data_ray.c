/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:35:42 by user42            #+#    #+#             */
/*   Updated: 2022/03/17 14:50:17 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_data_ray(t_data *data)
{
	data->ray.hit = 0;
	data->ray.perpwalldist = 0;
	data->ray.camerax = 2 * data->ray.x / (double)data->res_x - 1;
	data->ray.raydirx = data->ray.dirx + data->ray.planx
		* data->ray.camerax;
	data->ray.raydiry = data->ray.diry + data->ray.plany
		* data->ray.camerax;
	data->ray.mapx = (int)data->ray.posx;
	data->ray.mapy = (int)data->ray.posy;
	data->ray.movespeed = 0.1;
	data->ray.rotspeed = 0.1;
	if (data->ray.raydiry == 0)
		data->ray.deltadistx = 0;
	else if (data->ray.raydirx == 0)
		data->ray.deltadistx = 1;
	else
		data->ray.deltadistx = sqrt(1 + (data->ray.raydiry * data->ray.raydiry)
				/ (data->ray.raydirx * data->ray.raydirx));
	if (data->ray.raydirx == 0)
		data->ray.deltadisty = 0;
	else if (data->ray.raydiry == 0)
		data->ray.deltadisty = 1;
	else
		data->ray.deltadisty = sqrt(1 + (data->ray.raydirx * data->ray.raydirx)
				/ (data->ray.raydiry * data->ray.raydiry));
}
