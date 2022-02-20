/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rfc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:25:17 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 12:30:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_atoi2_more(const char *str, t_data *data)
{
	int	back;

	back = 0;
	while (str[data->i] >= '0' && str[data->i] <= '9')
		data->i++;
	if (str[data->i] != ' ' && str[data->i] != '\t' && str[data->i] != '\0')
		ft_error(data, "Error\nProblem with R\n");
	while (str[data->i] == ' ' || str[data->i] == '\t')
	{
		data->i++;
		back++;
	}
	if (str[data->i] == '0')
		ft_error(data, "Error\nProblem with R\n");
	while (back > 0)
	{
		data->i--;
		back--;
	}
}

int	ft_atoi2(const char *str, t_data *data)
{
	int	sum;

	sum = 0;
	if ((str[data->i] != ' ' && str[data->i] != '\t' && str[data->i] != '\0')
		|| ft_charinstr((char *)str, ',') == 1)
		ft_error(data, "Error\nProblem with R\n");
	while (str[data->i] == ' ' || str[data->i] == '\t'
		|| str[data->i] == ',')
		data->i++;
	while (str[data->i] >= '0' && str[data->i] <= '9')
	{
		if (sum > 21474636)
			break ;
		sum = (sum * 10) + (str[data->i] - 48);
		data->i++;
	}
	ft_atoi2_more(str, data);
	return (sum);
}

void	ft_recup_rfc2(char *str, t_data *data, int i)
{
	if (str[i] == 'R')
	{
		if (data->rx != 0 && data->ry != 0)
			ft_error(data, "Error\nProblem with R\n");
		data->rx = ft_atoi2(str, data);
		data->ry = ft_atoi2(str, data);
		if (ft_atoi2(str, data) > 0 || data->rx == 0 || data->ry == 0)
			ft_error(data, "Error\nProblem with R\n");
	}
	else if (str[i] == 'F')
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

void	ft_recup_rfc(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	data->i = i + 1;
	if (data->sizeline > 0 && (data->no == NULL || data->so == NULL
		|| data->we == NULL || data->ea == NULL))
		ft_error(data, "Error\nProblem of parsing\n");
	ft_recup_rfc2(str, data, i);
}
