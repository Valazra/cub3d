/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:45:16 by user42            #+#    #+#             */
/*   Updated: 2022/03/17 16:07:44 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_free_and_exit(t_data *data)
{
	int	i;

	i = -1;
	if (data->str_actual_gnl)
		free(data->str_actual_gnl);
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
	return (1);
}
