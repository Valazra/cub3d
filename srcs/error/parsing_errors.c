/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:27:19 by user42            #+#    #+#             */
/*   Updated: 2022/03/17 15:32:29 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parsing_errors(t_data *data)
{
	if (ft_first_line(data) == 1)
		ft_error(data, "Error\nProblem with first line\n");
	if (ft_first_last_carac(data) == 1)
		ft_error(data, "Error\nProblem with first or last carac\n");
	if (ft_surround(data) == 1)
		ft_error(data, "Error\nProblem with surround\n");
	if (data->nb_color_code != 6)
		ft_error(data, "Error\nProblem with F or C\n");
	if (data->multiplayer == 1)
		ft_error(data, "Error\nToo many players in the map\n");
	if (data->wrongcharmap == 1)
		ft_error(data, "Error\nBad character in the map\n");
	if (data->emptyline == 1)
		ft_error(data, "Error\nEmpty line in the map\n");
	if (data->depart == 'x')
		ft_error(data, "Error\nNo player in the map\n");
}
