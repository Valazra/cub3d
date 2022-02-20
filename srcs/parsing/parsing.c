/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:23:40 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 11:17:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_parsing_map(char *fichier, t_recup *recup)
{
	int		fd;
	int		ret;
	char	*str;

	ret = 1;
	str = NULL;
	fd = open(fichier, O_RDONLY);
	recup->map = malloc(sizeof(char *) * recup->nblines);
	if (!(recup->map))
		return (0);
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		ft_start_parsing_map(recup, str);
	}
	close(fd);
	ft_parsing_errors(recup);
//	ft_mlx(recup);
	return (0);
}

int	ft_fd(t_recup *recup, char *fichier)
{
	int	fd;

	fd = open(fichier, O_DIRECTORY);
	if (fd != -1)
		ft_error(recup, "Error\nFile is a directory\n");
	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		ft_error(recup, "Error\nInvalid file\n");
	return (fd);
}

//check si le fichier de la map n'est pas un dossier, et si il existe bien 
//et qu on a les droits pour lire dessus, puis parcoure tout le fichier, 
//recup les donnees R, F, C, (R a enlever dans nouveau sujet), recup les paths 
//des textures, et recup le nb de lignes de la map et la taille des lignes
void	ft_parsing_file(char *fichier, t_recup *recup)
{
	int		fd;
	int		ret;
	char	*str;

	ret = 1;
	str = NULL;
	fd = ft_fd(recup, fichier);
	recup->error = 0;
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		if (recup->error == 2)
			ft_error(recup, "Error\nParsing problem\n");
		ft_recup_rfc(str, recup);
		ft_parsing_texture(str, recup);
		ft_count_size_and_nb_lines_of_map(str, recup);
		free(str);
	}
	close(fd);
	if (recup->sizeline == 0 || recup->nblines == 0)
		ft_error(recup, "Error\nNo Map\n");
	ft_parsing_map(fichier, recup);
}

//check le nom du fichier de la map
int	ft_parsing_file_name(char *str, t_recup *recup)
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
			ft_error(recup, "Error\nBad file name\n");
			return (0);
		}
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u'
		&& str[i + 3] == 'b' && str[i + 4] == '\0')
		ft_parsing_file(str, recup);
	else
		ft_error(recup, "Error\nBad file name\n");
	return (0);
}
