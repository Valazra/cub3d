/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:25:17 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 14:58:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_atoi3_check2(const char *str, t_data *data, int i, int j)
{
	while ((str[i] < '0' || str[i] > '9') && str[i])
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		ft_error(data, "Error\nProblem with F or C\n");
	if (ft_count_nb_virgule(str) != 2)
		ft_error(data, "Error\nProblem of comma with F or C\n");
}

void	ft_atoi3_check(const char *str, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != ',')
		i++;
	if (str[i] == '\0')
		ft_error(data, "Error\nNo commas for F or C\n");
	if (str[i] == ',')
		j = 1;
	i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	ft_atoi3_check2(str, data, i, j);
}

void	ft_atoi3_more(const char *str, t_data *data, int verify)
{
	if (str[data->i] >= '0' && str[data->i] <= '9')
		data->nb_color_code++;
	while (str[data->i] == '0')
		data->i++;
	while (str[data->i] >= '0' && str[data->i] <= '9')
	{
		verify = (verify * 10) + str[data->i] - 48;
		data->sum = (data->sum * 10) + (str[data->i] - 48);
		data->i++;
	}
	if (verify > 255 || verify < 0)
		ft_error(data, "Error\nProblem with F or C\n");
}

int	ft_atoi3(const char *str, t_data *data)
{
	int	verify;

	data->sum = 0;
	if (str[data->i] != ' ' && str[data->i] != '\t')
		ft_error(data, "Error\nProblem with F or C\n");
	ft_atoi3_check(str, data);
	while (str[data->i] == ' ' || str[data->i] == '\t'
		|| str[data->i] == ',')
	{
		data->i++;
		verify = 0;
		ft_atoi3_more(str, data, verify);
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
	if (str[i] == 'F')
	{
		if (data->f != -1)
			ft_error(data, "Error\nToo much F\n");
		data->f = ft_atoi3(str, data);
	}
	else if (str[i] == 'C')
	{
		if (data->c != -1)
			ft_error(data, "Error\nToo much C\n");
		data->c = ft_atoi3(str, data);
	}
}
