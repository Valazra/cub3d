/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:34:27 by user42            #+#    #+#             */
/*   Updated: 2022/02/20 11:24:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "../minilibx_linux/mlx.h"

# define ROTATE_LEFT	65361
# define ROTATE_RIGHT	65363
# define FORWARD_W_Z	119
# define BACK_S_S	115
# define RIGHT_D_D	100
# define LEFT_A_Q	97
# define BUFFER_SIZE	4096

typedef struct s_texture
{
	int		texdir;
	double	wallx;
	int		texx;
	int		texy;
	double	step;
	double	texpos;
}		t_text;

typedef struct s_ray
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planx;
	double	plany;
	double	raydirx;
	double	raydiry;
	double	camerax;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	double	perpwalldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	movespeed;
	double	rotspeed;
	int		x;
	int		texture;
}			t_ray;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		forward;
	int		back;
	int		left;
	int		right;
	int		rotate_left;
	int		rotate_right;
	int		width;
	int		height;
	void	*img2;
	int		*addr2;
}			t_data;

typedef struct s_recup
{
	int		rx;
	int		ry;
	int		i;
	int		f;
	int		c;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		nblines;
	int		sizeline;
	char	**map;
	char	depart;
	int		dx;
	int		dy;
	int		indicateur;
	int		indicateur2;
	int		indicateur3;
	int		screenx;
	int		screeny;
	int		error;
	int		multiplayer;
	int		emptyline;
	int		insidemap;
	int		count;
	int		count2;
	int		sum;
	int		wrongcharmap;
	t_data	texture[4];
	t_data	data;
	t_ray	ray;
	t_text	t;
}			t_recup;

//GNL
int		get_next_line(int fd, char **line);

//PARSING
int		ft_parsing_file_name(char *str, t_recup *recup);
void	ft_recup_rfc(char *str, t_recup *recup);
int		ft_atoi3(const char *str, t_recup *recup);
void	ft_atoi3_check(const char *str, t_recup *recup);
void	ft_parsing_texture(char *str, t_recup *recup);
void	ft_count_size_and_nb_lines_of_map(char *str, t_recup *recup);
void	ft_start_parsing_map(t_recup *recup, char *str);
int		ft_is_map(char *str, t_recup *recup);
int		ft_copy_map(char *str, t_recup *recup);
int		ft_emptyline(char *str);
int		ft_first_last_carac(t_recup *recup);
int		ft_first_line(t_recup *recup);
int		ft_surround(t_recup *recup);
void	ft_parsing_errors(t_recup *recup);

//UTILS
int		ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int		ft_strlen2(char *str);
int		ft_nb_virgule(const char *str);
int		ft_charinstr(char *str, char c);

//INIT
void	ft_initialisation(t_recup *recup);
void	ft_initialisation2(t_recup *recup);
void	ft_initialisation3(t_recup *recup);
int		init_mlx(t_recup *recup);

//ERROR
void	ft_error(t_recup *recup, char *str);
int		ft_exit(t_recup *recup);

//MLX
int		ft_key_press(int keycode, t_recup *recup);
int		ft_key_release(int keycode, t_recup *recup);

//RAYCAST
int		ft_raycasting(t_recup *recup);
void	ft_get_texture(t_recup *recup);
void	ft_stepsidedist(t_recup *recup);
int		ft_color_column(t_recup *recup);
void	ft_forward_back(t_recup *recup);
void	ft_left_right(t_recup *recup);
void	ft_rotate_right_left(t_recup *recup);
void	ft_swap(t_recup *recup);

#endif
