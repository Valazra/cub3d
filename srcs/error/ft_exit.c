/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:54:10 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 13:05:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_exit(t_data *data)
{
	if (data->indicateur3 == 0)
		ft_error(data, "All is working\n");
	if (data->data_mlx.img)
		mlx_destroy_image(data->data_mlx.mlx_ptr, data->data_mlx.img);
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
