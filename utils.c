/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:56:04 by diogosan          #+#    #+#             */
/*   Updated: 2024/06/18 18:59:36 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_up_win(t_mlx *win)
{
	win->mlx_connect = 0;
	win->mlx_win = 0;
	win->map = 0;
	win->zoom = 10;
	win->z_zoom = 0.25;
	win->shift_x = 960;
	win->shift_y = 240;
	win->view = 0.78;
	win->c_factor = 1;
}

int	ft_max(int n1, int n2)
{
	int	n;

	n = n1 - n2;
	if (n > 0)
		return (n1);
	else
		return (n2);
}

int	ft_mod(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

int	ft_fdf_check(char *name)
{
	int		len_name;
	int		c;
	int		i;
	char	*sufix;

	sufix = ".fdf";
	len_name = ft_strlen(name);
	if (len_name <= 3)
		return (0);
	len_name -= 1;
	c = len_name - 3;
	i = 0;
	while (name[c])
	{
		if (name[c] != sufix[i])
			return (0);
		c++;
		i++;
	}
	return (1);
}

int	ft_rgb_to_int(char *color)
{
	int	c;
	int	result;

	result = 0;
	c = 2;
	while (ft_isdigit(color[c]) || (color[c] >= 'a' && color[c] <= 'f')
		|| (color[c] >= 'A' && color[c] <= 'F'))
	{
		result *= 16;
		if (color[c] <= '9')
			result += color[c] - '0';
		else if (color[c] >= 'a' && color[c] <= 'f')
			result += color[c] - 'a' + 10;
		else
			result += color[c] - 'A' + 10;
		c++;
	}
	return (result);
}
