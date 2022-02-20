/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:23:40 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 13:38:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//va incrementer nb_lines a chaque appel (gnl) et va mettre dans sizeline
//la taille de la plus grande ligne de la map
void	ft_count_size_and_nb_lines_of_map(char *str, t_data *data)
{
	int			i;
	static int	snblines = 0;
	static int	ssizeline = 0;

	i = 0;
	if (ft_is_map(str, data) == 1)
	{
		if (data->f == -1 || data->c == -1 || data->no == NULL ||
			data->so == NULL || data->we == NULL || data->ea == NULL)
			ft_error(data, "Error\nInformations missing\n");
		i = ft_strlen(str);
		if (i > ssizeline)
			ssizeline = i;
		snblines = snblines + 1;
	}
	data->nblines = snblines;
	data->sizeline = ssizeline;
}

int	ft_check_file(t_data *data, char *fichier)
{
	int	fd;

	fd = open(fichier, O_DIRECTORY);
	if (fd != -1)
		ft_error(data, "Error\nFile is a directory\n");
	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		ft_error(data, "Error\nInvalid file\n");
	return (fd);
}

//check si le fichier de la map n'est pas un dossier, et si il existe bien 
//et qu on a les droits pour lire dessus, puis parcoure tout le fichier, 
//data les donnees R, F, C, (R a enlever dans nouveau sujet), data les paths 
//des textures, et data le nb de lignes de la map et la taille des lignes
void	ft_parsing_file(char *fichier, t_data *data)
{
	int		fd;
	int		ret;
	char	*str;

	ret = 1;
	str = NULL;
	fd = ft_check_file(data, fichier);
	data->error = 0;
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		if (data->error == 2)
			ft_error(data, "Error\nParsing problem\n");
		ft_recup_fc(str, data);
		ft_parsing_texture(str, data);
		ft_count_size_and_nb_lines_of_map(str, data);
		free(str);
	}
	close(fd);
	if (data->sizeline == 0 || data->nblines == 0)
		ft_error(data, "Error\nNo Map\n");
	ft_set_map(fichier, data);
}

//check le nom du fichier de la map
int	ft_parsing_file_name(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
		{
			ft_error(data, "Error\nBad file name\n");
			return (0);
		}
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u'
		&& str[i + 3] == 'b' && str[i + 4] == '\0')
		ft_parsing_file(str, data);
	else
		ft_error(data, "Error\nBad file name\n");
	return (0);
}
