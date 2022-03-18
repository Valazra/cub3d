/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:39:28 by vazra             #+#    #+#             */
/*   Updated: 2022/03/17 15:44:40 by vazra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_mlx(t_data *data)
{
	mlx_hook(data->data_mlx.mlx_win, 33, 1L << 17, ft_free_and_exit, data);
	mlx_hook(data->data_mlx.mlx_win, 2, 1L << 0, ft_key_press, data);
	mlx_hook(data->data_mlx.mlx_win, 3, 1L << 1, ft_key_release, data);
	mlx_loop_hook(data->data_mlx.mlx_ptr, ft_render, data);
	mlx_loop(data->data_mlx.mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_init_data(&data);
	if (argc != 2)
		ft_error(&data, "Error\nBad number of args\n");
	ft_parsing_file_name(argv[1], &data);
	ft_init_render(&data);
	init_mlx(&data);
	start_mlx(&data);
}
