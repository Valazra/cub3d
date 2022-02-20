/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:25:44 by user42            #+#    #+#             */
/*   Updated: 2022/02/16 14:17:44 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_path_texture(char *str, char **texture, t_recup *recup, int i)
{
	recup->count2 = 0;
	if (*texture != NULL)
		ft_error(recup, "Error\nToo many ids\n");
	if (ft_charinstr(str, '.') == 0 || ft_charinstr(str, '/') == 0 \
		|| ft_strlen2(str) <= 2)
		ft_error(recup, "Error\nProblem with path of ids\n");
	while (str[i] != '.')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '.')
			ft_error(recup, "Error\nProblem with start of path\n");
		i++;
	}
	*texture = (char *)(malloc(sizeof(char) * (ft_strlen2(str) + 1)));
	if (!(*texture))
		ft_error(recup, "Error\nProblem with textures malloc\n");
	while (str[i] != '\0')
	{
		(*texture)[recup->count2] = str[i];
		recup->count2++;
		i++;
	}
	(*texture)[recup->count2] = '\0';
	return (0);
}

void	ft_exceptions(char *str, t_recup *recup, int i)
{
	if (str[i] == 'N' && str[i + 1] != 'O')
		ft_error(recup, "Error\nBad 'N'\n");
	if (str[i] == 'S' && str[i + 1] != 'O')
		ft_error(recup, "Error\nBad 'S'\n");
	if (str[i] == 'E' && str[i + 1] != 'A')
		ft_error(recup, "Error\nBad 'E'\n");
	if (str[i] == 'W' && str[i + 1] != 'E')
		ft_error(recup, "Error\nBad 'W'\n");
	if (str[i] == 'N' && str[i + 1] == 'O'
		&& (str[i + 2] != ' ' && str[i + 2] != '\t'))
		ft_error(recup, "Error\nBad 'N'\n");
	if (str[i] == 'S' && str[i + 1] == 'O'
		&& (str[i + 2] != ' ' && str[i + 2] != '\t'))
		ft_error(recup, "Error\nBad 'S'\n");
	if (str[i] == 'E' && str[i + 1] == 'A'
		&& (str[i + 2] != ' ' && str[i + 2] != '\t'))
		ft_error(recup, "Error\nBad 'E'\n");
	if (str[i] == 'W' && str[i + 1] == 'E'
		&& (str[i + 2] != ' ' && str[i + 2] != '\t'))
		ft_error(recup, "Error\nBad 'W'\n");
}

void	ft_parsing_texture(char *str, t_recup *recup)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == 'S' && str[i + 1] == 'O' && (str[i + 2] == ' ' \
		|| str[i + 2] == '\t'))
		ft_path_texture(str, &recup->no, recup, i + 2);
	else if (str[i] == 'N' && str[i + 1] == 'O' && (str[i + 2] == ' ' \
		|| str[i + 2] == '\t'))
		ft_path_texture(str, &recup->so, recup, i + 2);
	else if (str[i] == 'E' && str[i + 1] == 'A' && (str[i + 2] == ' ' \
		|| str[i + 2] == '\t'))
		ft_path_texture(str, &recup->we, recup, i + 2);
	else if (str[i] == 'W' && str[i + 1] == 'E' && (str[i + 2] == ' ' \
		|| str[i + 2] == '\t'))
		ft_path_texture(str, &recup->ea, recup, i + 2);
	else if (str[i] != 'N' && str[i] != 'S' && str[i] != 'W' && str[i] != 'E' \
		&& str[i] != 'R' && str[i] != 'F' && str[i] != 'C' \
			&& str[i] > 65 && str[i] < 122)
		ft_error(recup, "Error\nBad id\n");
	ft_exceptions(str, recup, i);
}
