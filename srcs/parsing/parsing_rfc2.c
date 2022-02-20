/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rfc2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:25:17 by user42            #+#    #+#             */
/*   Updated: 2022/02/16 14:18:15 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_atoi3_check2(const char *str, t_recup *recup, int i, int j)
{
	while ((str[i] < '0' || str[i] > '9') && str[i])
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		ft_error(recup, "Error\nProblem with F or C\n");
	if (ft_nb_virgule(str) != 2)
		ft_error(recup, "Error\nProblem of comma with F or C\n");
}

void	ft_atoi3_check(const char *str, t_recup *recup)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != ',')
		i++;
	if (str[i] == '\0')
		ft_error(recup, "Error\nNo commas for F or C\n");
	if (str[i] == ',')
		j = 1;
	i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	ft_atoi3_check2(str, recup, i, j);
}

void	ft_atoi3_more(const char *str, t_recup *recup, int verify)
{
	if (str[recup->i] >= '0' && str[recup->i] <= '9')
		recup->indicateur2++;
	while (str[recup->i] == '0')
		recup->i++;
	while (str[recup->i] >= '0' && str[recup->i] <= '9')
	{
		verify = (verify * 10) + str[recup->i] - 48;
		recup->sum = (recup->sum * 10) + (str[recup->i] - 48);
		recup->i++;
	}
	if (verify > 255 || verify < 0)
		ft_error(recup, "Error\nProblem with F or C\n");
}

int	ft_atoi3(const char *str, t_recup *recup)
{
	int	verify;

	recup->sum = 0;
	if (str[recup->i] != ' ' && str[recup->i] != '\t')
		ft_error(recup, "Error\nProblem with F or C\n");
	ft_atoi3_check(str, recup);
	while (str[recup->i] == ' ' || str[recup->i] == '\t'
		|| str[recup->i] == ',')
	{
		recup->i++;
		verify = 0;
		ft_atoi3_more(str, recup, verify);
	}
	return (recup->sum);
}
