/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:24:19 by user42            #+#    #+#             */
/*   Updated: 2022/03/17 14:27:16 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_emptyline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_first_line(t_data *data)
{
	int	i;

	i = -1;
	while (data->map[0][++i])
		if (data->map[0][i] != '1' && data->map[0][i] != ' ')
			return (1);
	return (0);
}

int	ft_first_last_carac(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->nblines - 1)
	{
		j = 0;
		while (data->map[i][j] == ' ')
			j++;
		if (data->map[i][j] != '1')
			return (1);
		while (data->map[i][j] != '\0')
			j++;
		j--;
		while (data->map[i][j] == ' ')
			j--;
		if (data->map[i][j] != '1')
			return (1);
		i++;
	}
	return (0);
}
