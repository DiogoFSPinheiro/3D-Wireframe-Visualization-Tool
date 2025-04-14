/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:28:06 by diogosan          #+#    #+#             */
/*   Updated: 2024/06/19 10:56:11 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(int *)pixel = color;
	}
}

void	render_background(t_img *img, int color)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_pixel_put(img, x++, y, color);
		}
		++y;
	}
}
