/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:23:40 by user42            #+#    #+#             */
/*   Updated: 2022/03/17 16:08:29 by jholl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_count_size_and_nb_lines_of_map(char *str, t_data *data)
{
	int			i;

	i = 0;
	if (ft_is_map(str, data) == 1)
	{
		if (data->f == -1 || data->c == -1 || data->no == NULL
			|| data->so == NULL || data->we == NULL || data->ea == NULL)
			ft_error(data, "Error\nInformations missing\n");
		i = ft_strlen(str);
		if (i > data->sizeline)
			data->sizeline = i;
		data->nblines++;
	}
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

void	ft_parsing_file(char *fichier, t_data *data)
{
	int		fd;
	int		ret;

	ret = 1;
	fd = ft_check_file(data, fichier);
	while (ret != 0)
	{
		ret = get_next_line(fd, &data->str_actual_gnl);
		ft_recup_fc(data->str_actual_gnl, data);
		ft_parsing_texture(data->str_actual_gnl, data);
		ft_count_size_and_nb_lines_of_map(data->str_actual_gnl, data);
		free(data->str_actual_gnl);
		data->str_actual_gnl = NULL;
	}
	close(fd);
	if (data->sizeline == 0 || data->nblines == 0)
		ft_error(data, "Error\nNo Map\n");
	ft_set_map(fichier, data);
}

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
