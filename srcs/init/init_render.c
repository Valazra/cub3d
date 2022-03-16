/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:22:35 by user42            #+#    #+#             */
/*   Updated: 2022/03/17 00:55:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_start_direction(t_data *data)
{
	if (data->depart == 'N')
		data->ray.dirx = -1;
	if (data->depart == 'S')
		data->ray.dirx = 1;
	if (data->depart == 'E')
		data->ray.diry = 1;
	if (data->depart == 'W')
		data->ray.diry = -1;
	if (data->depart == 'N')
		data->ray.plany = 0.66;
	if (data->depart == 'S')
		data->ray.plany = -0.66;
	if (data->depart == 'E')
		data->ray.planx = 0.66;
	if (data->depart == 'W')
		data->ray.planx = -0.66;
}

void	ft_init_render(t_data *data)
{
	data->data_mlx.forward = 0;
	data->data_mlx.back = 0;
	data->data_mlx.left = 0;
	data->data_mlx.right = 0;
	data->data_mlx.rotate_right = 0;
	data->data_mlx.rotate_left = 0;
	data->ray.posx = (double)data->pos_x + 0.5;
	data->ray.posy = (double)data->pos_y + 0.5;
	data->ray.dirx = 0;
	data->ray.diry = 0;
	data->ray.planx = 0;
	data->ray.plany = 0;
	ft_init_start_direction(data);
}
