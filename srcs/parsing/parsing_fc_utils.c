/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fc_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:35:20 by jholl             #+#    #+#             */
/*   Updated: 2022/03/18 12:22:31 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_there_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	init_data_rgb(t_data *data)
{
	data->rgb = 0;
	data->r = 0;
	data->g = 0;
	data->b = 0;
}
