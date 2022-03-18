/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_parse_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:24:31 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 13:08:07 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_depart(char c, t_data *data, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (data->depart != 'x')
			data->multiplayer = 1;
		data->depart = c;
		data->pos_x = i;
		data->pos_y = j;
		return (1);
	}
	return (0);
}

int	ft_copy_map(char *str, t_data *data)
{
	static int	i = 0;
	int			j;

	j = 0;
	data->map[i] = NULL;
	data->map[i] = malloc(sizeof(*data->map[i]) * data->sizeline + 1);
	if (!(data->map[i]))
		ft_error(data, "Error\nProblem with malloc\n");
	while (str[j] != '\0')
	{
		if (ft_depart(str[j], data, i, j) == 1)
			data->map[i][j] = '0';
		else
			data->map[i][j] = str[j];
		j++;
	}
	data->map[i][j] = '\0';
	while (j < data->sizeline)
	{
		data->map[i][j] = '\0';
		j++;
	}
	i++;
	return (0);
}

int	ft_is_map(char *str, t_data *data)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	if (ft_charinstr(str, '1') == 1 || ft_charinstr(str, '0') == 1)
	{
		while (str[i] != '\0')
		{
			if (str[i] != ' ' && str[i] != '0' && str[i] != '1' && str[i]
				!= 'N' && str[i] != 'S' && str[i] != 'E' && str[i] != 'W')
			{
				if (data->insidemap == 1)
					data->wrongcharmap = 1;
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_parsing_map(t_data *data, char *str)
{
	if (data->insidemap == 1 && ft_emptyline(str) == 1
		&& data->count < data->nblines)
		data->emptyline = 1;
	data->insidemap = ft_is_map(str, data);
	if (data->insidemap == 1)
	{
		data->count++;
		ft_copy_map(str, data);
	}
	free(data->str_actual_gnl);
	data->str_actual_gnl = NULL;
}

int	ft_set_map(char *fichier, t_data *data)
{
	int		fd;
	int		ret;

	ret = 1;
	fd = open(fichier, O_RDONLY);
	data->map = malloc(sizeof(char *) * data->nblines);
	if (!(data->map))
		ft_error(data, "Error\nProblem with malloc\n");
	while (ret != 0)
	{
		ret = get_next_line(fd, &data->str_actual_gnl);
		ft_parsing_map(data, data->str_actual_gnl);
	}
	close(fd);
	ft_parsing_errors(data);
	return (0);
}
