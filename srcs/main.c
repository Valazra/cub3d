/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vazra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:39:28 by vazra             #+#    #+#             */
/*   Updated: 2022/02/20 11:25:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	start_mlx(t_recup *recup)
{
	mlx_hook(recup->data.mlx_win, 33, 1L << 17, ft_exit, recup);
	mlx_hook(recup->data.mlx_win, 2, 1L << 0, ft_key_press, recup);
	mlx_loop_hook(recup->data.mlx_ptr, ft_raycasting, recup);
	mlx_hook(recup->data.mlx_win, 3, 1L << 1, ft_key_release, recup);
	mlx_loop(recup->data.mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_recup	recup;

	ft_initialisation(&recup);
	if (argc == 2)
		ft_parsing_file_name(argv[1], &recup);
	else
		ft_error(&recup, "Error\nBad number of args\n");
	ft_initialisation2(&recup);
	init_mlx(&recup);
	start_mlx(&recup);
}
