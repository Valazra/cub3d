/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:24:31 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 11:39:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_depart(char c, t_data *data, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (data->depart != 'x')
			data->multiplayer = 1;
		data->depart = c;
		data->dx = i;
		data->dy = j;
		return (1);
	}
	return (0);
}

//va creer dans data->map la map du fichier, en tcheckant la position de depart
//et en mettant ses coordonnes dans dx et dy (check aussi si multiplayers).
//Complete les lignes par des \0 jusqu'a sizeline (la ligne la plus grande)
int	ft_copy_map(char *str, t_data *data)
{
	static int	i = 0;
	int			j;

	j = 0;
	data->map[i] = NULL;
	data->map[i] = malloc(sizeof(*data->map[i]) * data->sizeline + 1);
	if (!(data->map[i]))
		return (0);
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

void	ft_start_parsing_map(t_data *data, char *str)
{
	if (data->insidemap == 1 && ft_emptyline(str) == 1 \
			&& data->count < data->nblines)
		data->emptyline = 1;
	data->insidemap = ft_is_map(str, data);
	if (data->insidemap == 1)
	{
		data->count++;
		ft_copy_map(str, data);
	}
	free(str);
}

//check si on est dans la map
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
			if (str[i] != ' ' && str[i] != '0' && str[i] != '1' && str[i] \
				!= 'N' && str[i] != 'S' && str[i] != 'E' && str[i] != 'W' \
				&& str[i] != '\n' && str[i] != '\t')
			{
				if (data->insidemap == 1)
					data->wrongcharmap = 2;
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

//va incrementer nb_lines a chaque appel (gnl) et va mettre dans sizeline
//la taille de la plus grande ligne de la map
void	ft_count_size_and_nb_lines_of_map(char *str, t_data *data)
{
	int			i;
	static int	snblines = 0;
	static int	ssizeline = 0;

	i = 0;
	if (ft_is_map(str, data) == 1)
	{
		if (data->f == -1 || data->c == -1 || data->no == NULL || \
			data->so == NULL || data->we == NULL || data->ea == NULL)
			ft_error(data, "Error\nInformations missing\n");
		i = ft_strlen(str);
		if (i > ssizeline)
			ssizeline = i;
		snblines = snblines + 1;
	}
	data->nblines = snblines;
	data->sizeline = ssizeline;
}
