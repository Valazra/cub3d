/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:23:05 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 11:11:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_key_press(int keycode, t_recup *recup)
{
	if (keycode == FORWARD_W_Z)
		recup->data.forward = 1;
	else if (keycode == BACK_S_S)
		recup->data.back = 1;
	else if (keycode == LEFT_A_Q)
		recup->data.left = 1;
	else if (keycode == RIGHT_D_D)
		recup->data.right = 1;
	else if (keycode == ROTATE_LEFT)
		recup->data.rotate_left = 1;
	else if (keycode == ROTATE_RIGHT)
		recup->data.rotate_right = 1;
	else if (keycode == 65307)
		ft_error(recup, "All is working\n");
	return (1);
}

int	ft_key_release(int keycode, t_recup *recup)
{
	if (keycode == FORWARD_W_Z)
		recup->data.forward = 0;
	else if (keycode == BACK_S_S)
		recup->data.back = 0;
	else if (keycode == LEFT_A_Q)
		recup->data.left = 0;
	else if (keycode == RIGHT_D_D)
		recup->data.right = 0;
	else if (keycode == ROTATE_LEFT)
		recup->data.rotate_left = 0;
	else if (keycode == ROTATE_RIGHT)
		recup->data.rotate_right = 0;
	return (1);
}
