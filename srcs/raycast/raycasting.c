/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:26:00 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 11:43:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_get_texture_adress(t_data *data)
{
	data->texture[0].addr = (int *)mlx_get_data_addr(data->texture[0].img,
		&data->texture[0].bits_per_pixel, &data->texture[0].line_length,
		&data->texture[0].endian);
	data->texture[1].addr = (int *)mlx_get_data_addr(data->texture[1].img,
		&data->texture[1].bits_per_pixel, &data->texture[1].line_length,
		&data->texture[1].endian);
	data->texture[2].addr = (int *)mlx_get_data_addr(data->texture[2].img,
		&data->texture[2].bits_per_pixel, &data->texture[2].line_length,
		&data->texture[2].endian);
	data->texture[3].addr = (int *)mlx_get_data_addr(data->texture[3].img,
		&data->texture[3].bits_per_pixel, &data->texture[3].line_length,
		&data->texture[3].endian);
}

void	ft_get_texture(t_data *data)
{
	data->texture[0].img = mlx_xpm_file_to_image(data->data_mlx.mlx_ptr,
		data->no, &(data->texture[0].width), &(data->texture[0].height));
	if (!(data->texture[0].img))
		ft_error(data, "Error\nProblem with Texture SO\n");
	data->texture[1].img = mlx_xpm_file_to_image(data->data_mlx.mlx_ptr,
		data->so, &(data->texture[1].width), &(data->texture[1].height));
	if (!(data->texture[1].img))
		ft_error(data, "Error\nProblem with Texture NO\n");
	data->texture[2].img = mlx_xpm_file_to_image(data->data_mlx.mlx_ptr,
		data->we, &(data->texture[2].width), &(data->texture[2].height));
	if (!(data->texture[2].img))
		ft_error(data, "Error\nProblem with Texture EA\n");
	data->texture[3].img = mlx_xpm_file_to_image(data->data_mlx.mlx_ptr,
		data->ea, &(data->texture[3].width), &(data->texture[3].height));
	if (!(data->texture[3].img))
		ft_error(data, "Error\nProblem with Texture WE\n");
	ft_get_texture_adress(data);
}
