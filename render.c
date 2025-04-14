/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:39:04 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/23 11:20:55 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
*	This simple way of calculating the isometric_view gets the job done 
*	I like simple stuff so i did it like this:
*	We transform x and y is transformed based on x new position
*	Lastly we subtract z to y to get the depth
*/
static void	isometric_view(t_point *p, float ang)
{
	p->x = (p->x - p->y) * cos(ang); // Rotate x and y coordinates
	p->y = (p->x + p->y) * sin(ang) - p->z; // Adjust y coordinate and subtract z for depth
}

/*
*	This part is rally simple
*	We mustiply n zoom to the point
*/
void	set_zoom(t_mlx *win, t_point *p1, t_point *p2)
{
	p1->x *= win->zoom;
	p1->y *= win->zoom;
	p1->z *= win->zoom;
	p1->z *= win->z_zoom;
	p2->x *= win->zoom;
	p2->y *= win->zoom;
	p2->z *= win->zoom;
	p2->z *= win->z_zoom;
}

/*
* So, lets do some math!
* There are many algs to draw a line. 
* I went with the bresenhams alg
*/
void	ft_bresenhams_alg(t_mlx *win, t_point p1, t_point p2)
{
	float	x_step;
	float	y_step;
	int		max;

    // Adjust points based on zoom level
	set_zoom(win, &p1, &p2); // Adjust p1 and p2 based on the zoom level set in win
    
	// Apply isometric view transformation if not in default view
	if (win->view != 3)
	{
		isometric_view(&p1, win->view); // Apply isometric view transformation to p1
		isometric_view(&p2, win->view); // Apply isometric view transformation to p2
	}
	// Apply shift offsets for positioning
	p1.x += win->shift_x;
	p1.y += win->shift_y;
	p2.x += win->shift_x;
	p2.y += win->shift_y;

	// Calculate step sizes for incremental drawing
	x_step = p2.x - p1.x;
	y_step = p2.y - p1.y;

	// Determine maximum absolute step to normalize
	max = ft_max(ft_mod(x_step), ft_mod(y_step)); // Find maximum step size between x_step and y_step
	x_step /= max; // Normalize x_step to ensure uniform incremental movement
	y_step /= max; // Normalize y_step to ensure uniform incremental movement
	
	// Loop to draw the line using Bresenham's algorithm
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		my_pixel_put(&win->img, p1.x, p1.y, p1.color * win->c_factor); // Draw a pixel at current coordinates p1 with adjusted color
		p1.x += x_step; // Increment x step of p1
		p1.y += y_step; // Increment y step of p1
	}
}

/*
*	In here happens all the creation of the image
*	I set the Background as a black screen and draw every line until i get the grid
*	on top of it
*	After i'm done e update the image
*/
int	draw(t_mlx *win)
{
	int	y;
	int	x;
	// Render a black background
	render_background(&win->img, 0x000000);
	y = 0;
	// Loop through each point in the map
	while (y < win->map->height)
	{
		x = 0;
		while (x < win->map->width)
		{
			// Draw horizontal lines between adjacent points in the same row
			if (x < win->map->width - 1)
				ft_bresenhams_alg(win, win->map->coord[y][x],
					win->map->coord[y][x + 1]);
			 // Draw vertical lines between adjacent points in the same column
			if (y < win->map->height - 1)
				ft_bresenhams_alg(win, win->map->coord[y][x],
					win->map->coord[y + 1][x]);
			x++;
		}
		y++;
	}
	// Display the rendered image onto the window
	mlx_put_image_to_window(win->mlx_connect, win->mlx_win,
		win->img.mlx_img, 0, 0);
	// Display additional elements on the screen (if any)
	ft_put_on_screen(win);
	return (0);
}

/*
*	This is were all the magic happens!
*/
void	render(t_map *map)
{
	t_mlx	*win;

	win = malloc(sizeof(t_mlx)); // Allocate memory for the window structure
	set_up_win(win); // Set up the window properties and initial configurations
	win->mlx_connect = mlx_init(); // Initialize connection to the MiniLibX library
	win->mlx_win = mlx_new_window(win->mlx_connect, WIDTH, HEIGHT, "Fdf"); // Create a new window with specified dimensions and title
	win->map = map; // Associate the map data with the window structure
	win->img.mlx_img = mlx_new_image(win->mlx_connect, WIDTH, HEIGHT); // Create a new image in memory with specified dimensions
	win->img.addr = mlx_get_data_addr(win->img.mlx_img, &win->img.bpp,
			&win->img.line_len, &win->img.endian); // Get the address information of the image for pixel manipulation
	mlx_loop_hook(win->mlx_connect, &draw, win); // Set up the draw function as a loop hook for continuous rendering
	mlx_key_hook(win->mlx_win, arrow_keys, win); // Set up keyboard event handling using arrow_keys function
	mlx_hook(win->mlx_win, KeyPress, KeyPressMask, ft_event_checker, win);  // Set up general event handling using ft_event_checker function
	mlx_hook(win->mlx_win, 17, 0, ft_close, win); // Set up a hook for closing events using ft_close function
	mlx_loop(win->mlx_connect); // Start the MiniLibX event loop for window interaction
}
