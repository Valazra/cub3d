/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rfc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:25:17 by user42            #+#    #+#             */
/*   Updated: 2022/02/16 14:19:37 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_atoi2_more(const char *str, t_recup *recup)
{
	int	back;

	back = 0;
	while (str[recup->i] >= '0' && str[recup->i] <= '9')
		recup->i++;
	if (str[recup->i] != ' ' && str[recup->i] != '\t' && str[recup->i] != '\0')
		ft_error(recup, "Error\nProblem with R\n");
	while (str[recup->i] == ' ' || str[recup->i] == '\t')
	{
		recup->i++;
		back++;
	}
	if (str[recup->i] == '0')
		ft_error(recup, "Error\nProblem with R\n");
	while (back > 0)
	{
		recup->i--;
		back--;
	}
}

int	ft_atoi2(const char *str, t_recup *recup)
{
	int	sum;

	sum = 0;
	if ((str[recup->i] != ' ' && str[recup->i] != '\t' && str[recup->i] != '\0')
		|| ft_charinstr((char *)str, ',') == 1)
		ft_error(recup, "Error\nProblem with R\n");
	while (str[recup->i] == ' ' || str[recup->i] == '\t'
		|| str[recup->i] == ',')
		recup->i++;
	while (str[recup->i] >= '0' && str[recup->i] <= '9')
	{
		if (sum > 21474636)
			break ;
		sum = (sum * 10) + (str[recup->i] - 48);
		recup->i++;
	}
	ft_atoi2_more(str, recup);
	return (sum);
}

void	ft_recup_rfc2(char *str, t_recup *recup, int i)
{
	if (str[i] == 'R')
	{
		if (recup->rx != 0 && recup->ry != 0)
			ft_error(recup, "Error\nProblem with R\n");
		recup->rx = ft_atoi2(str, recup);
		recup->ry = ft_atoi2(str, recup);
		if (ft_atoi2(str, recup) > 0 || recup->rx == 0 || recup->ry == 0)
			ft_error(recup, "Error\nProblem with R\n");
	}
	else if (str[i] == 'F')
	{
		if (recup->f != -1)
			ft_error(recup, "Error\nToo much F\n");
		recup->f = ft_atoi3(str, recup);
	}
	else if (str[i] == 'C')
	{
		if (recup->c != -1)
			ft_error(recup, "Error\nToo much C\n");
		recup->c = ft_atoi3(str, recup);
	}
}

void	ft_recup_rfc(char *str, t_recup *recup)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	recup->i = i + 1;
	if (recup->sizeline > 0 && (recup->no == NULL || recup->so == NULL \
		|| recup->we == NULL || recup->ea == NULL))
		ft_error(recup, "Error\nProblem of parsing\n");
	ft_recup_rfc2(str, recup, i);
}
