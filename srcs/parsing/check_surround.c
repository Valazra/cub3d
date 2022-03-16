/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_surround.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:24:19 by user42            #+#    #+#             */
/*   Updated: 2022/03/17 00:56:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_spaces(t_data *data, int i, int j)
{
	if (data->map[i - 1][j] == ' ' || data->map[i - 1][j] == '\0')
		return (1);
	if (data->map[i][j - 1] == ' ' || data->map[i][j - 1] == '\0')
		return (1);
	if (data->map[i][j + 1] == ' ' || data->map[i][j + 1] == '\0')
		return (1);
	if (data->map[i + 1][j] == ' ' || data->map[i + 1][j] == '\0')
		return (1);
	return (0);
}

int	ft_check_top(t_data *data, int i, int j)
{
	int	k;

	k = 0;
	while (k < i)
	{
		if (data->map[k][j] == '1')
			return (0);
		k++;
	}
	return (1);
}

int	ft_check_bottom(t_data *data, int i, int j)
{
	int	k;

	k = i;
	while (k < data->nblines)
	{
		if (data->map[k][j] == '1')
			return (0);
		k++;
	}
	return (1);
}

int	ft_check_line(t_data *data, int i, int j)
{
	while (data->map[i][j])
	{
		if (data->map[i][j] == '1')
			j++;
		else if (data->map[i][j] == '0')
		{
			if (ft_check_top(data, i, j) == 1)
				return (1);
			if (ft_check_bottom(data, i, j) == 1)
				return (1);
			if (ft_check_spaces(data, i, j) == 1)
				return (1);
			j++;
		}
		else
			j++;
	}
	return (0);
}

int	ft_surround(t_data *data)
{
	int	i;
	int	j;
	int	check;

	i = 1;
	while (i < data->nblines)
	{
		j = 0;
		check = ft_check_line(data, i, j);
		if (check == 1)
			return (1);
		else
			i++;
	}
	return (0);
}
