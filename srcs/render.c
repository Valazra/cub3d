/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:21:50 by user42            #+#    #+#             */
/*   Updated: 2022/03/17 15:15:05 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_texture(t_data *data)
{
	if (data->ray.side == 0 && data->ray.raydirx < 0)
		data->t.texdir = 0;
	if (data->ray.side == 0 && data->ray.raydirx >= 0)
		data->t.texdir = 1;
	if (data->ray.side == 1 && data->ray.raydiry < 0)
		data->t.texdir = 2;
	if (data->ray.side == 1 && data->ray.raydiry >= 0)
		data->t.texdir = 3;
	if (data->ray.side == 0)
		data->t.wallx = data->ray.posy + data->ray.perpwalldist
			* data->ray.raydiry;
	else
		data->t.wallx = data->ray.posx + data->ray.perpwalldist
			* data->ray.raydirx;
	data->t.wallx -= floor((data->t.wallx));
}

void	ft_draw_texture(t_data *data, int x, int y)
{
	y = data->ray.drawstart - 1;
	ft_init_texture(data);
	data->t.step = 1.0 * data->texture[0].height / data->ray.lineheight;
	data->t.texx = (int)(data->t.wallx
			* (double)data->texture[data->t.texdir].width);
	if (data->ray.side == 0 && data->ray.raydirx > 0)
		data->t.texx = data->texture[data->t.texdir].width
			- data->t.texx - 1;
	if (data->ray.side == 1 && data->ray.raydiry < 0)
		data->t.texx = data->texture[data->t.texdir].width
			- data->t.texx - 1;
	data->t.texpos = (data->ray.drawstart - data->res_y / 2
			+ data->ray.lineheight / 2) * data->t.step;
	while (++y <= data->ray.drawend)
	{
		data->t.texy = (int)data->t.texpos
			&(data->texture[data->t.texdir].height - 1);
		data->t.texpos += data->t.step;
		if (y < data->res_y && x < data->res_x)
			data->data_mlx.addr[y * data->data_mlx.line_length / 4 + x]
				= data->texture[data->t.texdir].addr[data->t.texy
				* data->texture[data->t.texdir].line_length / 4
				+ data->t.texx];
	}
}

int	ft_color_column(t_data *data)
{
	int	j;
	int	i;

	j = -1;
	data->ray.drawend = data->res_y - data->ray.drawstart;
	i = data->ray.drawend;
	while (++j < data->ray.drawstart)
		data->data_mlx.addr[j * data->data_mlx.line_length / 4
			+ data->ray.x] = data->c;
	if (j <= data->ray.drawend)
		ft_draw_texture(data, data->ray.x, j);
	j = i;
	while (++j < data->res_y)
		data->data_mlx.addr[j * data->data_mlx.line_length / 4
			+ data->ray.x] = data->f;
	return (0);
}

int	ft_render(t_data *data)
{
	data->ray.x = 0;
	while (data->ray.x < data->res_x)
	{
		ft_init_data_ray(data);
		ft_stepsidedist(data);
		ft_color_column(data);
		data->ray.x++;
	}
	mlx_put_image_to_window(data->data_mlx.mlx_ptr, data->data_mlx.mlx_win,
		data->data_mlx.img, 0, 0);
	ft_forward_back(data);
	ft_left_right(data);
	ft_rotate_right_left(data);
	return (0);
}
