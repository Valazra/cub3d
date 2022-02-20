/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:25:44 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 13:30:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_exceptions(char *str, t_data *data, int i)
{
	if (str[i] == 'N' && str[i + 1] != 'O')
		ft_error(data, "Error\nBad 'N'\n");
	if (str[i] == 'S' && str[i + 1] != 'O')
		ft_error(data, "Error\nBad 'S'\n");
	if (str[i] == 'E' && str[i + 1] != 'A')
		ft_error(data, "Error\nBad 'E'\n");
	if (str[i] == 'W' && str[i + 1] != 'E')
		ft_error(data, "Error\nBad 'W'\n");
	if (str[i] == 'N' && str[i + 1] == 'O'
		&& (str[i + 2] != ' ' && str[i + 2] != '\t'))
		ft_error(data, "Error\nBad 'N'\n");
	if (str[i] == 'S' && str[i + 1] == 'O'
		&& (str[i + 2] != ' ' && str[i + 2] != '\t'))
		ft_error(data, "Error\nBad 'S'\n");
	if (str[i] == 'E' && str[i + 1] == 'A'
		&& (str[i + 2] != ' ' && str[i + 2] != '\t'))
		ft_error(data, "Error\nBad 'E'\n");
	if (str[i] == 'W' && str[i + 1] == 'E'
		&& (str[i + 2] != ' ' && str[i + 2] != '\t'))
		ft_error(data, "Error\nBad 'W'\n");
}

int	ft_path_texture(char *str, char **texture, t_data *data, int i)
{
	data->count2 = 0;
	if (*texture != NULL)
		ft_error(data, "Error\nToo many ids\n");
	if (ft_charinstr(str, '.') == 0 || ft_charinstr(str, '/') == 0
		|| ft_count_digits_after_point(str) <= 2)
		ft_error(data, "Error\nProblem with path of ids\n");
	while (str[i] != '.')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '.')
			ft_error(data, "Error\nProblem with start of path\n");
		i++;
	}
	*texture = (char *)(malloc(sizeof(char) * (ft_count_digits_after_point(str) + 1)));
	if (!(*texture))
		ft_error(data, "Error\nProblem with textures malloc\n");
	while (str[i] != '\0')
	{
		(*texture)[data->count2] = str[i];
		data->count2++;
		i++;
	}
	(*texture)[data->count2] = '\0';
	return (0);
}

void	ft_parsing_texture(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == 'S' && str[i + 1] == 'O' && (str[i + 2] == ' '
		|| str[i + 2] == '\t'))
		ft_path_texture(str, &data->no, data, i + 2);
	else if (str[i] == 'N' && str[i + 1] == 'O' && (str[i + 2] == ' '
		|| str[i + 2] == '\t'))
		ft_path_texture(str, &data->so, data, i + 2);
	else if (str[i] == 'E' && str[i + 1] == 'A' && (str[i + 2] == ' '
		|| str[i + 2] == '\t'))
		ft_path_texture(str, &data->we, data, i + 2);
	else if (str[i] == 'W' && str[i + 1] == 'E' && (str[i + 2] == ' '
		|| str[i + 2] == '\t'))
		ft_path_texture(str, &data->ea, data, i + 2);
	else if (str[i] != 'N' && str[i] != 'S' && str[i] != 'W' && str[i] != 'E'
		&& str[i] != 'F' && str[i] != 'C'
			&& str[i] > 65 && str[i] < 122)
		ft_error(data, "Error\nBad id\n");
	ft_exceptions(str, data, i);
}
