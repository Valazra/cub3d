/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:34:27 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 12:27:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error(t_data *data, char *str)
{
	int	i;

	i = -1;
	data->indicateur3 = 1;
	write(2, str, ft_strlen(str));
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->map)
	{
		while (++i < data->nblines)
			free(data->map[i]);
	}
	if (data->map)
		free(data->map);
	ft_exit(data);
}

int	ft_exit(t_data *data)
{
	if (data->indicateur3 == 0)
		ft_error(data, "All is working\n");
	if (data->data_mlx.img)
		mlx_destroy_image(data->data_mlx.mlx_ptr, data->data_mlx.img);
	if (data->data_mlx.img2)
		mlx_destroy_image(data->data_mlx.mlx_ptr, data->data_mlx.img2);
	if (data->texture[0].img)
		mlx_destroy_image(data->data_mlx.mlx_ptr, data->texture[0].img);
	if (data->texture[1].img)
		mlx_destroy_image(data->data_mlx.mlx_ptr, data->texture[1].img);
	if (data->texture[2].img)
		mlx_destroy_image(data->data_mlx.mlx_ptr, data->texture[2].img);
	if (data->texture[3].img)
		mlx_destroy_image(data->data_mlx.mlx_ptr, data->texture[3].img);
	if (data->data_mlx.mlx_win)
		mlx_destroy_window(data->data_mlx.mlx_ptr, data->data_mlx.mlx_win);
	exit(0);
}
