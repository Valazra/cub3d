/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:05:04 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 11:34:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_more(t_data *data)
{
	data->depart = 'x';
	data->indicateur2 = 0;
	data->indicateur3 = 0;
	data->data_mlx.img = NULL;
	data->texture[0].img = NULL;
	data->texture[1].img = NULL;
	data->texture[2].img = NULL;
	data->texture[3].img = NULL;
	data->data_mlx.mlx_win = NULL;
	data->map = NULL;
}

void	ft_initialisation(t_data *data)
{
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->f = -1;
	data->c = -1;
	data->rx = 0;
	data->ry = 0;
	data->nblines = 0;
	data->sizeline = 0;
	data->dx = 0;
	data->dy = 0;
	data->multiplayer = 0;
	data->emptyline = 0;
	data->insidemap = 0;
	data->count = 0;
	data->sum = 0;
	data->wrongcharmap = 0;
	ft_init_more(data);
}
