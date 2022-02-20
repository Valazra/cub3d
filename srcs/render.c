/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:21:50 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 11:15:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_texture(t_recup *recup)
{
	if (recup->ray.side == 0 && recup->ray.raydirx < 0)
		recup->t.texdir = 0;
	if (recup->ray.side == 0 && recup->ray.raydirx >= 0)
		recup->t.texdir = 1;
	if (recup->ray.side == 1 && recup->ray.raydiry < 0)
		recup->t.texdir = 2;
	if (recup->ray.side == 1 && recup->ray.raydiry >= 0)
		recup->t.texdir = 3;
	if (recup->ray.side == 0)
		recup->t.wallx = recup->ray.posy + recup->ray.perpwalldist
			* recup->ray.raydiry;
	else
		recup->t.wallx = recup->ray.posx + recup->ray.perpwalldist
			* recup->ray.raydirx;
	recup->t.wallx -= floor((recup->t.wallx));
}

void	ft_draw_texture(t_recup *recup, int x, int y)
{
	y = recup->ray.drawstart - 1;
	ft_init_texture(recup);
	recup->t.step = 1.0 * recup->texture[0].height / recup->ray.lineheight;
	recup->t.texx = (int)(recup->t.wallx
		* (double)recup->texture[recup->t.texdir].width);
	if (recup->ray.side == 0 && recup->ray.raydirx > 0)
		recup->t.texx = recup->texture[recup->t.texdir].width
			- recup->t.texx - 1;
	if (recup->ray.side == 1 && recup->ray.raydiry < 0)
		recup->t.texx = recup->texture[recup->t.texdir].width
			- recup->t.texx - 1;
	recup->t.texpos = (recup->ray.drawstart - recup->ry / 2
		+ recup->ray.lineheight / 2) * recup->t.step;
	while (++y <= recup->ray.drawend)
	{
		recup->t.texy = (int)recup->t.texpos \
			&(recup->texture[recup->t.texdir].height - 1);
		recup->t.texpos += recup->t.step;
		if (y < recup->ry && x < recup->rx)
			recup->data.addr[y * recup->data.line_length / 4 + x] =
				recup->texture[recup->t.texdir].addr[recup->t.texy
				* recup->texture[recup->t.texdir].line_length / 4
					+ recup->t.texx];
	}
}

int	ft_color_column(t_recup *recup)
{
	int	j;
	int	i;

	j = -1;
	recup->ray.drawend = recup->ry - recup->ray.drawstart;
	i = recup->ray.drawend;
	while (++j < recup->ray.drawstart)
		recup->data.addr[j * recup->data.line_length / 4 \
			+ recup->ray.x] = recup->c;
	if (j <= recup->ray.drawend)
		ft_draw_texture(recup, recup->ray.x, j);
	j = i;
	while (++j < recup->ry)
		recup->data.addr[j * recup->data.line_length / 4 \
			+ recup->ray.x] = recup->f;
	return (0);
}

int	ft_raycasting(t_recup *recup)
{
	recup->ray.x = 0;
	while (recup->ray.x < recup->rx)
	{
		ft_initialisation3(recup);
		ft_stepsidedist(recup);
		ft_color_column(recup);
		recup->ray.x++;
	}
	mlx_put_image_to_window(recup->data.mlx_ptr, recup->data.mlx_win, \
		recup->data.img, 0, 0);
	ft_forward_back(recup);
	ft_left_right(recup);
	ft_rotate_right_left(recup);
	return (0);
}

