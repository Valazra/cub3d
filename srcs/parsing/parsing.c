/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:23:40 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 11:38:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_parsing_map(char *fichier, t_data *data)
{
	int		fd;
	int		ret;
	char	*str;

	ret = 1;
	str = NULL;
	fd = open(fichier, O_RDONLY);
	data->map = malloc(sizeof(char *) * data->nblines);
	if (!(data->map))
		return (0);
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		ft_start_parsing_map(data, str);
	}
	close(fd);
	ft_parsing_errors(data);
	return (0);
}

int	ft_fd(t_data *data, char *fichier)
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
	fd = ft_fd(data, fichier);
	data->error = 0;
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		if (data->error == 2)
			ft_error(data, "Error\nParsing problem\n");
		ft_data_rfc(str, data);
		ft_parsing_texture(str, data);
		ft_count_size_and_nb_lines_of_map(str, data);
		free(str);
	}
	close(fd);
	if (data->sizeline == 0 || data->nblines == 0)
		ft_error(data, "Error\nNo Map\n");
	ft_parsing_map(fichier, data);
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
