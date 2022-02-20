/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:34:27 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 12:53:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error(t_data *data, char *str)
{
	int	i;

	i = -1;
	data->indicateur3 = 1;
	write(2, str, ft_strlen(str));
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->map)
	{
		while (++i < data->nblines)
			free(data->map[i]);
	}
	if (data->map)
		free(data->map);
	ft_exit(data);
}
