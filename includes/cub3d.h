/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <vazra@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:34:27 by user42            #+#    #+#             */
/*   Updated: 2022/03/18 12:26:12 by jholl            ###   ########.fr       */
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

typedef struct s_data_mlx
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
}			t_data_mlx;

typedef struct s_data
{
	int			res_x;
	int			res_y;
	int			f;
	int			c;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			nblines;
	int			sizeline;
	char		**map;
	int			i;
	int			count;
	int			set_texture;
	int			sum;
	char		depart;
	int			pos_x;
	int			pos_y;
	int			nb_color_code;
	int			multiplayer;
	int			wrongcharmap;
	int			emptyline;
	int			insidemap;
	int			rgb;
	int			r;
	int			g;
	int			b;
	char		*str_actual_gnl;
	t_data_mlx	texture[4];
	t_data_mlx	data_mlx;
	t_ray		ray;
	t_text		t;
}			t_data;

//GLOBAL_UTILS
int		ft_count_nb_virgule(const char *str);
int		ft_charinstr(char *str, char c);

//GNL
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin_free(char *s1, char *s2);
int		ft_str_free(char *s);

//INIT
void	ft_init_data(t_data *data);
void	ft_init_render(t_data *data);
void	ft_init_data_ray(t_data *data);
int		init_mlx(t_data *data);

//PARSING
int		ft_parsing_file_name(char *str, t_data *data);
int		ft_set_map(char *fichier, t_data *data);
void	ft_recup_fc(char *str, t_data *data);
void	ft_parsing_texture(char *str, t_data *data);
int		ft_is_map(char *str, t_data *data);
int		ft_copy_map(char *str, t_data *data);
int		ft_emptyline(char *str);
int		ft_first_last_carac(t_data *data);
int		ft_first_line(t_data *data);
int		ft_surround(t_data *data);
int		encode_rgb(int red, int green, int blue);
void	init_data_rgb(t_data *data);
int		is_there_digit(char c);

//RAYCAST
int		ft_render(t_data *data);
void	ft_stepsidedist(t_data *data);
int		ft_color_column(t_data *data);
void	ft_forward_back(t_data *data);
void	ft_left_right(t_data *data);
void	ft_rotate_right_left(t_data *data);
int		ft_key_press(int keycode, t_data *data);
int		ft_key_release(int keycode, t_data *data);

//ERROR
void	ft_error(t_data *data, char *str);
int		ft_free_and_exit(t_data *data);
int		ft_exit(t_data *data);
void	ft_parsing_errors(t_data *data);

#endif
