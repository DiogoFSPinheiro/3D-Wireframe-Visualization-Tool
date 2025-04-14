/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:51:05 by diogosan          #+#    #+#             */
/*   Updated: 2024/06/20 09:36:13 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error_clean(int fd, char *str)
{
	int	i;

	i = ft_strlen(str);
	write(1, "Error -> Not a file or not enough Permissions\n", i);
	close(fd);
	exit(EXIT_FAILURE);
}

void	ft_put_on_screen(t_mlx *win)
{
	mlx_string_put(win->mlx_connect, win->mlx_win, 1820, 20, -1,
		"By diogosan");
	mlx_string_put(win->mlx_connect, win->mlx_win, 35, 20, -1,
		"Use arrow key to move");
	mlx_string_put(win->mlx_connect, win->mlx_win, 35, 40, -1,
		"Use - or + for Zoom");
	mlx_string_put(win->mlx_connect, win->mlx_win, 35, 60, -1,
		"Use z or x to level Z axys");
	mlx_string_put(win->mlx_connect, win->mlx_win, 35, 80, -1,
		"Press 1, 2 or 3 to change views");
	mlx_string_put(win->mlx_connect, win->mlx_win, 35, 100, -1,
		"Press c to change colors");
	mlx_string_put(win->mlx_connect, win->mlx_win, 35, 120, -1,
		"Press r to reset");
	mlx_string_put(win->mlx_connect, win->mlx_win, 35, 140, -1,
		"Press d to see a neat rotation");
	mlx_string_put(win->mlx_connect, win->mlx_win, 35, 160, -1,
		"Press esq or X icon to exit");
}

void	ft_reset(t_mlx *win)
{
	win->zoom = 10;
	win->z_zoom = 0.25;
	win->shift_x = 960;
	win->shift_y = 240;
	win->view = 0.78;
	win->c_factor = 1;
}
