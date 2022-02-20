/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:26:00 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 11:20:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_get_texture_adress(t_recup *recup)
{
	recup->texture[0].addr = (int *)mlx_get_data_addr(recup->texture[0].img,
		&recup->texture[0].bits_per_pixel, &recup->texture[0].line_length,
		&recup->texture[0].endian);
	recup->texture[1].addr = (int *)mlx_get_data_addr(recup->texture[1].img,
		&recup->texture[1].bits_per_pixel, &recup->texture[1].line_length,
		&recup->texture[1].endian);
	recup->texture[2].addr = (int *)mlx_get_data_addr(recup->texture[2].img,
		&recup->texture[2].bits_per_pixel, &recup->texture[2].line_length,
		&recup->texture[2].endian);
	recup->texture[3].addr = (int *)mlx_get_data_addr(recup->texture[3].img,
		&recup->texture[3].bits_per_pixel, &recup->texture[3].line_length,
		&recup->texture[3].endian);
}

void	ft_get_texture(t_recup *recup)
{
	recup->texture[0].img = mlx_xpm_file_to_image(recup->data.mlx_ptr,
		recup->no, &(recup->texture[0].width), &(recup->texture[0].height));
	if (!(recup->texture[0].img))
		ft_error(recup, "Error\nProblem with Texture SO\n");
	recup->texture[1].img = mlx_xpm_file_to_image(recup->data.mlx_ptr,
		recup->so, &(recup->texture[1].width), &(recup->texture[1].height));
	if (!(recup->texture[1].img))
		ft_error(recup, "Error\nProblem with Texture NO\n");
	recup->texture[2].img = mlx_xpm_file_to_image(recup->data.mlx_ptr,
		recup->we, &(recup->texture[2].width), &(recup->texture[2].height));
	if (!(recup->texture[2].img))
		ft_error(recup, "Error\nProblem with Texture EA\n");
	recup->texture[3].img = mlx_xpm_file_to_image(recup->data.mlx_ptr,
		recup->ea, &(recup->texture[3].width), &(recup->texture[3].height));
	if (!(recup->texture[3].img))
		ft_error(recup, "Error\nProblem with Texture WE\n");
	ft_get_texture_adress(recup);
}
