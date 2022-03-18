/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:54:10 by user42            #+#    #+#             */
/*   Updated: 2022/03/17 15:54:09 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit(t_data *data)
{
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
	if (data->data_mlx.mlx_ptr)
		mlx_destroy_display(data->data_mlx.mlx_ptr);
	if (data->data_mlx.mlx_ptr)
		free(data->data_mlx.mlx_ptr);
	exit(0);
}
