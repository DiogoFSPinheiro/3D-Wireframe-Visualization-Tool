/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:43:05 by diogosan          #+#    #+#             */
/*   Updated: 2024/07/03 16:58:11 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	more_keys(int Key, t_mlx *mlx);

void	ft_cleanup_and_exit(t_mlx *mlx)
{
	// If there is a valid connection to the MLX library
	if (mlx->mlx_connect != NULL)
	{
		// Destroy the image associated with the connection
		mlx_destroy_image(mlx->mlx_connect, mlx->img.mlx_img);
		// If there is a valid window, destroy it
		if (mlx->mlx_win != NULL)
			mlx_destroy_window(mlx->mlx_connect, mlx->mlx_win);
		// Destroy the display associated with the connection
		mlx_destroy_display(mlx->mlx_connect);
		// Free the memory allocated for the MLX connection
		free(mlx->mlx_connect);
	}
	// If there is a valid map, free its memory
	if (mlx->map != NULL)
		free_map(mlx->map);
	// Free the memory allocated for the MLX structure itself
	free(mlx);
	// Exit the program
	exit(0);
}

int	ft_close(t_mlx *mlx)
{
	ft_cleanup_and_exit(mlx);
	return (0);
}

int	ft_event_checker(int Key, t_mlx *mlx)
{
	if (Key == XK_Escape)
		ft_cleanup_and_exit(mlx);
	return (0);
}

int	arrow_keys(int Key, t_mlx *mlx)
{
	if (Key == XK_Right)
		mlx->shift_x += 10;
	if (Key == XK_Left)
		mlx->shift_x -= 10;
	if (Key == XK_Up)
		mlx->shift_y -= 10;
	if (Key == XK_Down)
		mlx->shift_y += 10;
	if (Key == XK_equal)
		mlx->zoom += 1;
	if (Key == XK_minus && mlx->zoom >= 2)
		mlx->zoom -= 1;
	if (Key == XK_z)
		mlx->z_zoom += 0.25;
	if (Key == XK_x)
		mlx->z_zoom -= 0.25;
	if (Key == XK_r)
		ft_reset(mlx);
	more_keys(Key, mlx);
	return (0);
}

static int	more_keys(int Key, t_mlx *mlx)
{
	if (Key == XK_1)
		mlx->view = 0.78;
	if (Key == XK_2)
		mlx->view = 0;
	if (Key == XK_3)
		mlx->view = 3;
	if (Key == XK_c)
		mlx->c_factor += 0.45;
	if (Key == XK_d)
		mlx->view += 0.1;
	return (0);
}
