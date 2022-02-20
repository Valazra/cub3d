/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:24:19 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 11:39:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//check si une ligne est vide dans la map
int	ft_emptyline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\0' && str[i] != '\n' \
				&& str[i] != '\r' && str[i] != '\v' && str[i] != '\f')
			return (0);
		i++;
	}
	return (1);
}

//check si la premiere ligne de la map est bien
int	ft_first_line(t_data *data)
{
	int	i;

	i = -1;
	while (data->map[0][++i])
		if (data->map[0][i] != '1' && data->map[0][i] != ' ')
			return (1);
	return (0);
}

//check pour chaque ligne de la map si elle commence bien 
//par un mur et termine par un mur (hormis les espaces)
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
