/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:25:17 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 12:40:54 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_fc2(const char *str, t_data *data, int i, int j)
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == ',')
	{
		i++;
		j++;
	}
	if (j != 2)
		ft_error(data, "Error\nProblem with F or C\n");
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!is_there_digit(str[i]))
		ft_error(data, "Error\nNeed R, G, B values for F or C\n");
	if (ft_count_nb_virgule(str) != 2)
		ft_error(data, "Error\nProblem of comma with F or C\n");
}

void	ft_check_fc(const char *str, t_data *data)
{
	int	i;
	int	j;

	i = data->i;
	j = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!is_there_digit(str[i]))
		ft_error(data, "Error\nNeed R, G, B values for F or C\n");
	while (str[i] && str[i] != ',')
		i++;
	if (str[i] == '\0')
		ft_error(data, "Error\nNo commas for F or C\n");
	if (str[i] == ',')
		j = 1;
	i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!is_there_digit(str[i]))
		ft_error(data, "Error\nNeed R, G, B values for F or C\n");
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	ft_check_fc2(str, data, i, j);
}

void	ft_fill_fc(const char *str, t_data *data, int verify)
{
	if (str[data->i] >= '0' && str[data->i] <= '9')
	{
		data->nb_color_code++;
		data->rgb++;
	}
	while (str[data->i] == '0')
		data->i++;
	while (str[data->i] >= '0' && str[data->i] <= '9')
	{
		verify = (verify * 10) + str[data->i] - 48;
		if (data->rgb == 1)
			data->r = verify;
		if (data->rgb == 2)
			data->g = verify;
		if (data->rgb == 3)
			data->b = verify;
		data->i++;
	}
	if (verify > 255 || verify < 0)
		ft_error(data, "Error\nProblem with F or C\n");
}

int	ft_set_fc(const char *str, t_data *data)
{
	int	verify;

	data->sum = 0;
	if (str[data->i] != ' ' && str[data->i] != '\t')
		ft_error(data, "Error\nProblem with F or C\n");
	ft_check_fc(str, data);
	while (str[data->i] == ' ' || str[data->i] == '\t'
		|| str[data->i] == ',')
	{
		data->i++;
		verify = 0;
		ft_fill_fc(str, data, verify);
	}
	return (data->sum);
}

void	ft_recup_fc(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	data->i = i + 1;
	if (data->sizeline > 0 && (data->no == NULL || data->so == NULL
			|| data->we == NULL || data->ea == NULL))
		ft_error(data, "Error\nProblem of parsing\n");
	init_data_rgb(data);
	if (str[i] == 'F')
	{
		if (data->f != -1)
			ft_error(data, "Error\nToo much F\n");
		ft_set_fc(str, data);
		data->f = encode_rgb(data->r, data->g, data->b);
	}
	else if (str[i] == 'C')
	{
		if (data->c != -1)
			ft_error(data, "Error\nToo much C\n");
		ft_set_fc(str, data);
		data->c = encode_rgb(data->r, data->g, data->b);
	}
}
