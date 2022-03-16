/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:23:05 by user42            #+#    #+#             */
/*   Updated: 2022/03/17 00:57:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_press(int keycode, t_data *data)
{
	if (keycode == FORWARD_W_Z)
		data->data_mlx.forward = 1;
	else if (keycode == BACK_S_S)
		data->data_mlx.back = 1;
	else if (keycode == LEFT_A_Q)
		data->data_mlx.left = 1;
	else if (keycode == RIGHT_D_D)
		data->data_mlx.right = 1;
	else if (keycode == ROTATE_LEFT)
		data->data_mlx.rotate_left = 1;
	else if (keycode == ROTATE_RIGHT)
		data->data_mlx.rotate_right = 1;
	else if (keycode == 65307)
		ft_free_and_exit(data);
	return (1);
}

int	ft_key_release(int keycode, t_data *data)
{
	if (keycode == FORWARD_W_Z)
		data->data_mlx.forward = 0;
	else if (keycode == BACK_S_S)
		data->data_mlx.back = 0;
	else if (keycode == LEFT_A_Q)
		data->data_mlx.left = 0;
	else if (keycode == RIGHT_D_D)
		data->data_mlx.right = 0;
	else if (keycode == ROTATE_LEFT)
		data->data_mlx.rotate_left = 0;
	else if (keycode == ROTATE_RIGHT)
		data->data_mlx.rotate_right = 0;
	return (1);
}
