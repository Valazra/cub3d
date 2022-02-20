/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:24:31 by user42            #+#    #+#             */
/*   Updated: 2022/02/16 14:18:58 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_depart(char c, t_recup *recup, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (recup->depart != 'x')
			recup->multiplayer = 1;
		recup->depart = c;
		recup->dx = i;
		recup->dy = j;
		return (1);
	}
	return (0);
}

//va creer dans recup->map la map du fichier, en tcheckant la position de depart
//et en mettant ses coordonnes dans dx et dy (check aussi si multiplayers).
//Complete les lignes par des \0 jusqu'a sizeline (la ligne la plus grande)
int	ft_copy_map(char *str, t_recup *recup)
{
	static int	i = 0;
	int			j;

	j = 0;
	recup->map[i] = NULL;
	recup->map[i] = malloc(sizeof(*recup->map[i]) * recup->sizeline + 1);
	if (!(recup->map[i]))
		return (0);
	while (str[j] != '\0')
	{
		if (ft_depart(str[j], recup, i, j) == 1)
			recup->map[i][j] = '0';
		else
			recup->map[i][j] = str[j];
		j++;
	}
	recup->map[i][j] = '\0';
	while (j < recup->sizeline)
	{
		recup->map[i][j] = '\0';
		j++;
	}
	i++;
	return (0);
}

void	ft_start_parsing_map(t_recup *recup, char *str)
{
	if (recup->insidemap == 1 && ft_emptyline(str) == 1 \
			&& recup->count < recup->nblines)
		recup->emptyline = 1;
	recup->insidemap = ft_is_map(str, recup);
	if (recup->insidemap == 1)
	{
		recup->count++;
		ft_copy_map(str, recup);
	}
	free(str);
}

//check si on est dans la map
int	ft_is_map(char *str, t_recup *recup)
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
				if (recup->insidemap == 1)
					recup->wrongcharmap = 2;
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
void	ft_count_size_and_nb_lines_of_map(char *str, t_recup *recup)
{
	int			i;
	static int	snblines = 0;
	static int	ssizeline = 0;

	i = 0;
	if (ft_is_map(str, recup) == 1)
	{
		if (recup->f == -1 || recup->c == -1 || recup->no == NULL || \
			recup->so == NULL || recup->we == NULL || recup->ea == NULL)
			ft_error(recup, "Error\nInformations missing\n");
		i = ft_strlen(str);
		if (i > ssizeline)
			ssizeline = i;
		snblines = snblines + 1;
	}
	recup->nblines = snblines;
	recup->sizeline = ssizeline;
}
