/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rfc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:25:17 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 13:25:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
