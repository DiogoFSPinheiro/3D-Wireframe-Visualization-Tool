/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:37:41 by diogosan          #+#    #+#             */
/*   Updated: 2024/06/20 09:37:53 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <sys/wait.h>
# include <signal.h>
# include "libraries/libft/libft.h"
# include "libraries/printf/ft_printf.h"
//# include "libraries/get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_point
{
	float				x;
	float				y;
	int					z;
	int					color;
}	t_point;

typedef struct s_map
{
	int					width;
	int					height;
	t_point				**coord;
}	t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_connect;
	void	*mlx_win;
	t_map	*map;
	int		zoom;
	float	z_zoom;
	int		shift_x;
	int		shift_y;
	float	view;
	float	c_factor;
	t_img	img;
}	t_mlx;

//---------data converter------
t_map	*ft_convert_data(char *filemap);
int		ft_get_dimensions(int *x, int *y, char *filename);
void	ft_error_clean(int fd, char *str);
//---------Math----------------
int		ft_mod(int n);
int		ft_max(int n1, int n2);
void	ft_bresenhams_alg(t_mlx *win, t_point p1, t_point p2);
//---------Events--------------
int		arrow_keys(int Key, t_mlx *mlx);
int		ft_event_checker(int Key, t_mlx *mlx);
//---------Render--------------
void	render(t_map *map);
int		draw(t_mlx *win);
void	set_up_win(t_mlx *win);
void	ft_reset(t_mlx *win);
void	ft_put_on_screen(t_mlx *win);
//---------Utils---------------
int		ft_fdf_check(char *name);
void	print_map(t_map	*map);
int		ft_rgb_to_int(char *color);
//---------CleanUp-------------
void	ft_cleanup_and_exit(t_mlx *mlx);
int		ft_close(t_mlx *mlx);
void	free_map(t_map *map);
//---------Creating my pixles---
void	my_pixel_put(t_img *img, int x, int y, int color);
void	render_background(t_img *img, int color);

#endif
