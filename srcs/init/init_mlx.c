/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:20:26 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 11:25:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_mlx(t_recup *recup)
{
	recup->data.mlx_ptr = mlx_init();
	if (!(recup->data.mlx_ptr))
		ft_error(recup, "Error\nProblem with mlx init\n");
	mlx_get_screen_size(recup->data.mlx_ptr, &recup->screenx, &recup->screeny);
	if (recup->rx > recup->screenx)
		recup->rx = recup->screenx;
	if (recup->ry > recup->screeny)
		recup->ry = recup->screeny;
	ft_get_texture(recup);
	recup->data.img = mlx_new_image(recup->data.mlx_ptr, recup->rx, recup->ry);
	recup->data.addr = (int *)mlx_get_data_addr(recup->data.img,
		&recup->data.bits_per_pixel, &recup->data.line_length,
		&recup->data.endian);
	recup->data.mlx_win = mlx_new_window(recup->data.mlx_ptr,
		recup->rx, recup->ry, "cub3D");
	recup->data.img2 = mlx_new_image(recup->data.mlx_ptr, recup->rx, recup->ry);
	recup->data.addr2 = (int *)mlx_get_data_addr(recup->data.img2,
		&recup->data.bits_per_pixel, &recup->data.line_length,
		&recup->data.endian);
	return (0);
}
