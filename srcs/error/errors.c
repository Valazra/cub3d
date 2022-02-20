/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:34:27 by user42            #+#    #+#             */
/*   Updated: 2022/02/10 13:45:30 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_parsing_errors(t_recup *recup)
{
	if (ft_first_line(recup) == 1)
		ft_error(recup, "Error\nProblem with first line\n");
	if (ft_first_last_carac(recup) == 1)
		ft_error(recup, "Error\nProblem with first or last carac\n");
	if (ft_surround(recup) == 1)
		ft_error(recup, "Error\nProblem with surround\n");
	if (recup->indicateur2 != 6)
		ft_error(recup, "Error\nProblem with F or C\n");
	if (recup->emptyline == 1)
		ft_error(recup, "Error\nEmpty line in the map\n");
	if (recup->wrongcharmap == 2)
		ft_error(recup, "Error\nBad character in the map\n");
	if (recup->depart == 'x')
		ft_error(recup, "Error\nNo player in the map\n");
	if (recup->multiplayer == 1)
		ft_error(recup, "Error\nToo much players in the map\n");
}

void	ft_error(t_recup *recup, char *str)
{
	int	i;

	i = -1;
	recup->indicateur3 = 1;
	write(2, str, ft_strlen(str));
	if (recup->no)
		free(recup->no);
	if (recup->so)
		free(recup->so);
	if (recup->we)
		free(recup->we);
	if (recup->ea)
		free(recup->ea);
	if (recup->map)
	{
		while (++i < recup->nblines)
			free(recup->map[i]);
	}
	if (recup->map)
		free(recup->map);
	ft_exit(recup);
}

int	ft_exit(t_recup *recup)
{
	if (recup->indicateur3 == 0)
		ft_error(recup, "All is working\n");
	if (recup->data.img)
		mlx_destroy_image(recup->data.mlx_ptr, recup->data.img);
	if (recup->data.img2)
		mlx_destroy_image(recup->data.mlx_ptr, recup->data.img2);
	if (recup->texture[0].img)
		mlx_destroy_image(recup->data.mlx_ptr, recup->texture[0].img);
	if (recup->texture[1].img)
		mlx_destroy_image(recup->data.mlx_ptr, recup->texture[1].img);
	if (recup->texture[2].img)
		mlx_destroy_image(recup->data.mlx_ptr, recup->texture[2].img);
	if (recup->texture[3].img)
		mlx_destroy_image(recup->data.mlx_ptr, recup->texture[3].img);
	if (recup->data.mlx_win)
		mlx_destroy_window(recup->data.mlx_ptr, recup->data.mlx_win);
	exit(0);
}
