/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:20:26 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 11:43:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_mlx(t_data *data)
{
	data->data_mlx.mlx_ptr = mlx_init();
	if (!(data->data_mlx.mlx_ptr))
		ft_error(data, "Error\nProblem with mlx init\n");
	mlx_get_screen_size(data->data_mlx.mlx_ptr, &data->screenx, &data->screeny);
	if (data->rx > data->screenx)
		data->rx = data->screenx;
	if (data->ry > data->screeny)
		data->ry = data->screeny;
	ft_get_texture(data);
	data->data_mlx.img = mlx_new_image(data->data_mlx.mlx_ptr, data->rx, data->ry);
	data->data_mlx.addr = (int *)mlx_get_data_addr(data->data_mlx.img,
		&data->data_mlx.bits_per_pixel, &data->data_mlx.line_length,
		&data->data_mlx.endian);
	data->data_mlx.mlx_win = mlx_new_window(data->data_mlx.mlx_ptr,
		data->rx, data->ry, "cub3D");
	data->data_mlx.img2 = mlx_new_image(data->data_mlx.mlx_ptr, data->rx, data->ry);
	data->data_mlx.addr2 = (int *)mlx_get_data_addr(data->data_mlx.img2,
		&data->data_mlx.bits_per_pixel, &data->data_mlx.line_length,
		&data->data_mlx.endian);
	return (0);
}
