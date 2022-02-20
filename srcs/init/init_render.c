/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:22:35 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 11:04:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init2_more(t_recup *recup)
{
	if (recup->depart == 'N')
		recup->ray.dirx = -1;
	if (recup->depart == 'S')
		recup->ray.dirx = 1;
	if (recup->depart == 'E')
		recup->ray.diry = 1;
	if (recup->depart == 'W')
		recup->ray.diry = -1;
	if (recup->depart == 'N')
		recup->ray.plany = 0.66;
	if (recup->depart == 'S')
		recup->ray.plany = -0.66;
	if (recup->depart == 'E')
		recup->ray.planx = 0.66;
	if (recup->depart == 'W')
		recup->ray.planx = -0.66;
}

void	ft_initialisation2(t_recup *recup)
{
	recup->data.forward = 0;
	recup->data.back = 0;
	recup->data.left = 0;
	recup->data.right = 0;
	recup->data.rotate_right = 0;
	recup->data.rotate_left = 0;
	recup->ray.posx = (double)recup->dx + 0.5;
	recup->ray.posy = (double)recup->dy + 0.5;
	recup->ray.dirx = 0;
	recup->ray.diry = 0;
	recup->ray.planx = 0;
	recup->ray.plany = 0;
	ft_init2_more(recup);
}

