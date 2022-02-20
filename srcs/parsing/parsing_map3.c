/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:24:19 by user42            #+#    #+#             */
/*   Updated: 2022/02/10 14:42:01 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_spaces(t_recup *recup, int i, int j)
{
	if (recup->map[i - 1][j] == ' ')
		return (1);
	if (recup->map[i][j - 1] == ' ')
		return (1);
	if (recup->map[i][j + 1] == ' ')
		return (1);
	if (recup->map[i + 1][j] == ' ')
		return (1);
	return (0);
}

int	ft_check_top(t_recup *recup, int i, int j)
{
	int	k;

	k = 0;
	while (k < i)
	{
		if (recup->map[k][j] == '1')
			return (0);
		k++;
	}
	return (1);
}

int	ft_check_bottom(t_recup *recup, int i, int j)
{
	int	k;

	k = i;
	while (k < recup->nblines)
	{
		if (recup->map[k][j] == '1')
			return (0);
		k++;
	}
	return (1);
}

int	ft_check(t_recup *recup, int i, int j)
{
	while (recup->map[i][j])
	{
		if (recup->map[i][j] == '1')
			j++;
		else if (recup->map[i][j] == '0')
		{
			if (ft_check_top(recup, i, j) == 1)
				return (1);
			if (ft_check_bottom(recup, i, j) == 1)
				return (1);
			if (ft_check_spaces(recup, i, j) == 1)
				return (1);
			j++;
		}
		else
			j++;
	}
	return (0);
}

//check si la map est bien entouree de murs
int	ft_surround(t_recup *recup)
{
	int	i;
	int	j;
	int	check;

	i = 1;
	while (i < recup->nblines)
	{
		j = 0;
		check = ft_check(recup, i, j);
		if (check == 1)
			return (1);
		else
			i++;
	}
	return (0);
}
