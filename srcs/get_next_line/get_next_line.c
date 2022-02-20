/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholl <jholl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:37:17 by jholl             #+#    #+#             */
/*   Updated: 2022/02/20 12:46:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_new_line(char *current_line)
{
	while (*current_line)
	{
		if (*current_line == '\n')
			return (1);
		current_line++;
	}
	return (0);
}

char	*cut_current_line(char *current_line)
{
	int			i;
	char		*temp;

	i = 0;
	while (current_line[i] && current_line[i] != '\n')
		i++;
	temp = ft_substr(current_line, 0, i);
	ft_str_free(current_line);
	if (!temp)
		return (NULL);
	return (temp);
}

void	cut_content_read(char *content_read)
{
	int			i;
	int			j;

	i = 0;
	while (content_read[i] && content_read[i] != '\n')
		i++;
	if (content_read[i])
		i++;
	j = 0;
	while (content_read[i])
	{
		content_read[j] = content_read[i];
		i++;
		j++;
	}
	content_read[j] = '\0';
}

int	new_return(char *line, int val_read)
{
	if (!line)
		return (-1);
	if (val_read == 0)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	content_read[BUFFER_SIZE + 1];
	char		*current_line;
	int			val_read;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	current_line = NULL;
	current_line = ft_substr(content_read, 0, BUFFER_SIZE);
	if (!current_line)
		return (-1);
	val_read = 1;
	while (!is_new_line(current_line) && val_read > 0)
	{
		val_read = read(fd, content_read, BUFFER_SIZE);
		if (val_read < 0)
			return (ft_str_free(current_line));
		content_read[val_read] = '\0';
		current_line = ft_strjoin_free(current_line, content_read);
		if (!current_line)
			return (-1);
	}
	cut_content_read(content_read);
	*line = cut_current_line(current_line);
	return (new_return(*line, val_read));
}
