/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:05:04 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 11:05:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_more(t_recup *recup)
{
	recup->depart = 'x';
	recup->indicateur2 = 0;
	recup->indicateur3 = 0;
	recup->data.img = NULL;
	recup->texture[0].img = NULL;
	recup->texture[1].img = NULL;
	recup->texture[2].img = NULL;
	recup->texture[3].img = NULL;
	recup->data.mlx_win = NULL;
	recup->map = NULL;
}

void	ft_initialisation(t_recup *recup)
{
	recup->no = NULL;
	recup->so = NULL;
	recup->we = NULL;
	recup->ea = NULL;
	recup->f = -1;
	recup->c = -1;
	recup->rx = 0;
	recup->ry = 0;
	recup->nblines = 0;
	recup->sizeline = 0;
	recup->dx = 0;
	recup->dy = 0;
	recup->multiplayer = 0;
	recup->emptyline = 0;
	recup->insidemap = 0;
	recup->count = 0;
	recup->sum = 0;
	recup->wrongcharmap = 0;
	ft_init_more(recup);
}
