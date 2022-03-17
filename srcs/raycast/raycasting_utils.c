/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:27:00 by user42            #+#    #+#             */
/*   Updated: 2022/03/17 15:00:43 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_drawstartend(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.perpwalldist = ((double)data->ray.mapx - data->ray.posx
				+ (1 - (double)data->ray.stepx) / 2) / data->ray.raydirx;
	else
		data->ray.perpwalldist = ((double)data->ray.mapy - data->ray.posy
				+ (1 - (double)data->ray.stepy) / 2) / data->ray.raydiry;
	data->ray.lineheight = (int)(data->res_y / data->ray.perpwalldist);
	data->ray.drawstart = -data->ray.lineheight / 2 + data->res_y / 2;
	if (data->ray.drawstart < 0)
		data->ray.drawstart = 0;
}

void	ft_incrementray(t_data *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.sidedistx < data->ray.sidedisty)
		{
			data->ray.sidedistx += data->ray.deltadistx;
			data->ray.mapx += data->ray.stepx;
			data->ray.side = 0;
		}
		else
		{
			data->ray.sidedisty += data->ray.deltadisty;
			data->ray.mapy += data->ray.stepy;
			data->ray.side = 1;
		}
		if (data->map[data->ray.mapx][data->ray.mapy] == '1')
			data->ray.hit = 1;
	}
	ft_drawstartend(data);
}

void	ft_stepsidedist(t_data *data)
{
	if (data->ray.raydirx < 0)
	{
		data->ray.stepx = -1;
		data->ray.sidedistx = (data->ray.posx - data->ray.mapx)
			* data->ray.deltadistx;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.sidedistx = (data->ray.mapx + 1.0 - data->ray.posx)
			* data->ray.deltadistx;
	}
	if (data->ray.raydiry < 0)
	{
		data->ray.stepy = -1;
		data->ray.sidedisty = (data->ray.posy - data->ray.mapy)
			* data->ray.deltadisty;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.sidedisty = (data->ray.mapy + 1.0 - data->ray.posy)
			* data->ray.deltadisty;
	}
	ft_incrementray(data);
}
