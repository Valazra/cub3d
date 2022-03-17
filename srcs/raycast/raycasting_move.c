/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:26:11 by user42            #+#    #+#             */
/*   Updated: 2022/03/17 02:32:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_forward_back(t_data *data)
{
	if (data->data_mlx.forward == 1)
	{
		if (data->map[(int)(data->ray.posx + (data->ray.dirx
					* data->ray.movespeed * 2))][(int)data->ray.posy] == '0')
			data->ray.posx += data->ray.dirx * data->ray.movespeed;
		if (data->map[(int)(data->ray.posx)][(int)(data->ray.posy +
					(data->ray.diry * data->ray.movespeed * 2))] == '0')
			data->ray.posy += data->ray.diry * data->ray.movespeed;
	}
	if (data->data_mlx.back == 1)
	{
		if (data->map[(int)(data->ray.posx - (data->ray.dirx
					* data->ray.movespeed * 2))][(int)(data->ray.posy)] == '0')
			data->ray.posx -= data->ray.dirx * data->ray.movespeed;
		if (data->map[(int)(data->ray.posx)][(int)(data->ray.posy
			- (data->ray.diry * data->ray.movespeed * 2))] == '0')
			data->ray.posy -= data->ray.diry * data->ray.movespeed;
	}
}

void	ft_left_right(t_data *data)
{
	if (data->data_mlx.right == 1)
	{
		if (data->map[(int)(data->ray.posx + data->ray.diry
				* (data->ray.movespeed * 2))][(int)data->ray.posy] == '0')
			data->ray.posx += data->ray.diry * data->ray.movespeed;
		if (data->map[(int)data->ray.posx][(int)(data->ray.posy
			- data->ray.dirx * (data->ray.movespeed * 2))] == '0')
			data->ray.posy -= data->ray.dirx * data->ray.movespeed;
	}
	if (data->data_mlx.left == 1)
	{
		if (data->map[(int)(data->ray.posx - data->ray.diry
				* (data->ray.movespeed * 2))][(int)data->ray.posy] == '0')
			data->ray.posx -= data->ray.diry * data->ray.movespeed;
		if (data->map[(int)data->ray.posx][(int)(data->ray.posy
			+ data->ray.dirx * (data->ray.movespeed * 2))] == '0')
			data->ray.posy += data->ray.dirx * data->ray.movespeed;
	}
}

void	ft_rotate_left(t_data *data, double olddirx)
{
	double	oldplanex;

	if (data->data_mlx.rotate_left == 1)
	{
		olddirx = data->ray.dirx;
		oldplanex = data->ray.planx;
		data->ray.dirx = data->ray.dirx * cos(data->ray.rotspeed / 2)
			- data->ray.diry * sin(data->ray.rotspeed / 2);
		data->ray.diry = olddirx * sin(data->ray.rotspeed / 2)
			+ data->ray.diry * cos(data->ray.rotspeed / 2);
		data->ray.planx = data->ray.planx * cos(data->ray.rotspeed / 2)
			- data->ray.plany * sin(data->ray.rotspeed / 2);
		data->ray.plany = oldplanex * sin(data->ray.rotspeed / 2)
			+ data->ray.plany * cos(data->ray.rotspeed / 2);
	}
}

void	ft_rotate_right_left(t_data *data)
{
	double	oldplanx;
	double	olddirx;

	oldplanx = data->ray.planx;
	olddirx = data->ray.dirx;
	if (data->data_mlx.rotate_right == 1)
	{
		data->ray.dirx = data->ray.dirx * cos(-data->ray.rotspeed / 2)
			- data->ray.diry * sin(-data->ray.rotspeed / 2);
		data->ray.diry = olddirx * sin(-data->ray.rotspeed / 2)
			+ data->ray.diry * cos(-data->ray.rotspeed / 2);
		data->ray.planx = data->ray.planx * cos(-data->ray.rotspeed / 2)
			- data->ray.plany * sin(-data->ray.rotspeed / 2);
		data->ray.plany = oldplanx * sin(-data->ray.rotspeed / 2)
			+ data->ray.plany * cos(-data->ray.rotspeed / 2);
	}
	ft_rotate_left(data, olddirx);
}
