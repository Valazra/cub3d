/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:15:05 by user42            #+#    #+#             */
/*   Updated: 2021/06/18 15:02:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_fill(char *dst, const char *s, int *i)
{
	int	j;

	j = 0;
	while (s[j])
	{
		dst[*i] = s[j];
		j++;
		(*i)++;
	}
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	ft_fill(dst, s1, &i);
	ft_fill(dst, s2, &i);
	dst[i] = '\0';
	return (dst);
}

void	ft_isolator(char **stock, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((*stock)[i] != '\n' && (*stock)[i] != '\0')
		i++;
	*line = ft_substr(*stock, 0, i);
	if (i + 1 > ft_strlen(*stock))
	{
		free(*stock);
		*stock = NULL;
	}
	else
	{
		tmp = ft_substr(*stock, i + 1, ft_strlen(*stock));
		free(*stock);
		*stock = ft_strdup(tmp);
		free(tmp);
	}
}

int	ft_fork(char **stock, char **line, ssize_t by)
{
	if (by < 0)
	{
		free(*stock);
		*stock = NULL;
		return (-1);
	}
	else if (by == 0 && !*stock)
	{
		*line = ft_strdup("");
		return (0);
	}
	else if (!(ft_strchr(*stock, '\n')))
	{
		*line = ft_strdup(*stock);
		free(*stock);
		*stock = NULL;
		return (0);
	}
	else
	{
		ft_isolator(stock, line);
		return (1);
	}
}

int	get_next_line(int fd, char **line)
{
	ssize_t		by;
	char		buff[BUFFER_SIZE + 1];
	static char	*stock[256];
	char		*temp;

	if (fd < 0 || fd > 256 || !line || BUFFER_SIZE < 1)
		return (-1);
	by = read(fd, buff, BUFFER_SIZE);
	while (by > 0)
	{
		buff[by] = '\0';
		if (!(stock[fd]))
			stock[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strdup(stock[fd]);
			free(stock[fd]);
			stock[fd] = ft_strjoin(temp, buff);
			free(temp);
		}
		if (ft_strchr(stock[fd], '\n'))
			break ;
		by = read(fd, buff, BUFFER_SIZE);
	}
	return (ft_fork(&(stock[fd]), line, by));
}
