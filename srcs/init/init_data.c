/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:05:04 by user42            #+#    #+#             */
/*   Updated: 2022/03/17 16:06:48 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_more(t_data *data)
{
	data->depart = 'x';
	data->nb_color_code = 0;
	data->data_mlx.img = NULL;
	data->texture[0].img = NULL;
	data->texture[1].img = NULL;
	data->texture[2].img = NULL;
	data->texture[3].img = NULL;
	data->data_mlx.mlx_win = NULL;
	data->data_mlx.mlx_ptr = NULL;
	data->map = NULL;
	data->str_actual_gnl = NULL;
}

void	ft_init_data(t_data *data)
{
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->f = -1;
	data->c = -1;
	data->res_x = 0;
	data->res_y = 0;
	data->nblines = 0;
	data->sizeline = 0;
	data->pos_x = 0;
	data->pos_y = 0;
	data->multiplayer = 0;
	data->wrongcharmap = 0;
	data->emptyline = 0;
	data->insidemap = 0;
	data->count = 0;
	data->sum = 0;
	ft_init_more(data);
}
