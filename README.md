# Step by Step Guide of the FDF Project

![image](https://github.com/DiogoFSPinheiro/42_Rank_02/assets/143399294/839dd643-01af-4d3f-9932-5dd45bbbf794)

The FDF project, short for "Fil de Fer," is a 42School project aimed at introducing students to graphical programming. The objective is to create a simple wireframe model viewer that reads data from a file and displays a 3D representation of the data.

**Objectives of the Project**

* Learn how to read and parse data from a file.
* Understand the basics of graphical programming.
* Implement algorithms to project 3D points onto a 2D plane.
* Enhance visualization with colors and depth effects.

**Required Tools and Software**

* GCC (GNU Compiler Collection)
* MiniLibX (a simple graphics library used in 42 projects)
* A text editor or IDE of your choice (e.g., Vim, VS Code)

**Understanding the Basics**

A wireframe model is a visual representation of a 3D object using lines to connect the vertices of the object. It is a skeletal representation where only the edges and vertices are drawn, giving a clear outline of the shape without any surfaces. Wireframes are used extensively in computer graphics to represent 3D objects in a simplified form, making it easier to manipulate and view the structure of complex models.

In the context of the FDF project, you'll be working with a 3D wireframe model that is rendered on a 2D screen. This involves projecting 3D points onto a 2D plane, a fundamental concept in computer graphics.

## Setting Up the Graphics Library

To visualize your wireframe model, you'll need a graphics library. The FDF project typically uses the MiniLibX library for rendering graphics. Here are the steps to set up MiniLibX and integrate it into your project.

1. Installing MiniLibX

On macOS:

```sh
brew install minilibx
```
On Linux:

You might need to follow specific instructions provided in the MiniLibX repository or your school's documentation. Generally, you can clone the MiniLibX repository and compile it:
```sh
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux
make
```

1.1 MiniLibX Flags and dir
```sh
MINILXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lbsd -no-pie
LIBX = ./minilibx-linux/libmlx_Linux.a
```

1.2 Small example of how to create a new Window with MiniLibX
```sh
#include "mlx.h"        // Include MiniLibX header for graphical functions
#include <stdlib.h>     // Include standard library for exit()
#include <stdio.h>      // Include standard I/O library for perror()

#define WIDTH 800    // Define constant for window width
#define HEIGHT 600   // Define constant for window height

int handle_key(int keycode, void *param)  <- Key event handler function
{
    if (keycode == 65307)                 <- Check if Escape key (keycode 65307) is pressed
    {
        exit(0);                          <- Exit program gracefully
    }
    return (0);
}

int main()
{
    void *mlx_ptr;          <- Pointer to your connection to the X server (MiniLibX context)
    void *win_ptr;          <- Pointer to your window on the X server

    // Initialize MiniLibX and create a new window
    mlx_ptr = mlx_init();   <- Initialize MiniLibX and obtain a connection to X server

    win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "FDF");
                            | Create a new window with specified dimensions and title

    mlx_key_hook(win_ptr, handle_key, NULL);
                            | Set up key event handling for the created window

    mlx_loop(mlx_ptr);       <- Main loop to keep the window open and handle events

    return 0;
}
```
## The project involves the following main tasks
- `Reading a Map File:` The map file contains elevation data for a grid of points. Each point on the grid represents a vertex in the wireframe model, and the elevation data determines the z-coordinate of the vertex.
- `Parsing the Data:` Once the map file is read, the data needs to be parsed and stored in a suitable data structure. Typically, a 2D array of t_point structures is used to store the elevation values and other attributes.
- `Projecting 3D Points onto a 2D Plane:` The 3D points from the map file need to be projected onto a 2D plane to be displayed on the screen. This involves using mathematical transformations to convert 3D coordinates (x, y, z) into 2D coordinates (x, y).
- `Rendering the Wireframe:` The final step is to render the wireframe model on the screen. This involves drawing lines between the projected 2D points to represent the edges of the 3D object.
- `Adding Color and Depth:` To enhance the visual appearance, colors can be added based on the elevation values, and shading techniques can be used to give a sense of depth.

# Step-by-Step Implementation
In this section, we'll walk through the step-by-step implementation of the FDF project. This includes reading and parsing the map file, projecting 3D points, rendering the wireframe, and adding color and depth.
Firstly we need to make a struck to hold the data, i made this way but you can make any struck i deem necessary
```sh
typedef struct s_point <- This will hold the Values of wach point on the map
{
	float    x;
	float    y;
	int      z;              <- Value found on (x,y)
	int      color;          <- Value found after "," , if it doesnt have value we say its White
}	t_point;

typedef struct s_map // This will hold all the points of th map
{
	int        width;
	int        height;
	t_point    **coord;
}	t_map;

typedef struct s_img // This is need for building the image
{
	void    *mlx_img;          <- Pointer to the image
	char    *addr;             <- Images Adress
	int     bpp;               <- Bits per Pixel
	int     line_len;          <- Line of Image
	int     endian;
}	t_img;

typedef struct s_mlx // This will be our visual environment
{
	void    *mlx_connect;      <- Pointer to the mlx connection
	void    *mlx_win;          <- Pointer to the mlx window
	t_map    *map;             <- Our map
	int      zoom;             <- Bonus Part
	float    z_zoom;           <-     |
	int      shift_x;          <-     |
	int      shift_y;          <-     |
	float    view;             <-     |
	float    c_factor;         <-     |
	t_img    img;              <- Our image
}	t_mlx;
```

## 1st Step - Reading and Parsing the Map File
To start, you need to read the map file that contains the data and parse it into a usable data structure.
### 1. Map dimensions
* The ft_get_dimensions as the name says gets the dimensions of the map
* The get_next_line func is very handy in this situation!
* Dont forget to close the file...we dont want any errors
* And dont forget to free all the lines after reading then...we dont want any leaks
```sh
int	ft_get_dimensions(int *x, int *y, char *filename)
{
	char	*line;
	int		fd;
	*y = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_clean(fd, "Error -> Not a file or not enough Permissions\n");
	line = get_next_line(fd);
	if (!line)
		ft_error_clean(fd, "Error -> No info on file\n");
	*x = words(line, ' ');
	while (line)
	{
		*y = *y + 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}
```
### 2. Now with the dimensions lets try and read the map
* Again the get_next_line func is very handy in this situation!
* With dimensions we can alloc memory and fill the map struct.
* Free all the lines after reading then...leaks are annoying xD
```sh
t_map	*ft_convert_data(char *filemap)
{
	t_map	*map;
	char	*line;
	int		fd;
	int		x;
	int		y;
	ft_get_dimensions(&x, &y, filemap);
	map = malloc(sizeof(t_map));
	map->width = x;
	map->height = y;
	map->coord = malloc(map->height * sizeof(t_point *));
	y = 0;
	fd = open(filemap, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map->coord[y] = malloc(map->width * sizeof(t_point));
		ft_fill_matix(map->coord[y], line, y);
		free(line);
		y++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map);
}
```
### 3. Filling the matrix and saving the data in a point struck
* Remember the ft_split func? Time to put it to use!
* We need to se if we have color info on that coordenate and save it.
* To do that we use the ft_fill_matix func
* Again, free all the lines after reading then...leaks are annoying xD
```sh
void	ft_fill_matix(t_point *row, char *line, int y)
{
	char	**data;
	int		c;
	c = 0;
	data = ft_split(line, ' ');
	while (data[c])
	{
		ft_set_point(&row[c], data[c], c, y);
		free(data[c]);
		c++;
	}
	free(data);
}
```
### 3.1 Time to set the points
* We save every data we think will be usefull on each point
* Lets use ft_split again but this time with a ","
* Again if we dont find any color we make it white (0xffffff)
* Why 0xffffff? We can divide this as 0x(R)ff(G)ff(B)ff - RGB - RED GREEN BLUE
* As we know the color white is all the colors together so its all ffs xD
```sh
void	ft_set_point(t_point *point, char *str, int x, int y)
{
	char	**data;
	data = ft_split(str, ',');
	point->z = ft_atoi(data[0]);
	point->x = x;
	point->y = y;
	if (data[1])
		point->color = ft_rgb_to_int(data[1]);
	else
		point->color = 0xffffff;
	free_args(data);
}
```
## 2nd Step - Drawing the Wireframe
So, now that we have all the data ready let start drawing.
To draw we need to learn some new concepts:
* `Bresenham's Algorithm:` This is a line drawing algorithm that efficiently determines the points of an approximation of a straight line between two points in a 2D space. 
* `Isometric View Transformation:` This transformation is used to project 3D points onto a 2D plane in a way that preserves relative distances along the x, y, and z axes.
* `Rendering and Display:` Utilizing libraries like MiniLibX to create windows, handle events (such as key presses), and continuously redraw the scene (using functions like mlx_loop and mlx_put_image_to_window) to provide an interactive graphical interface.

### 1. Bresenham's Algorithm
The algo Works like this:

  [1] Determine the initial coordinates (x1, y1) and (x2, y2) of the line;
    
  [2] Calculate the delta_x dx = x2 - x1 and delta_y dy = y2 - y1 to understand the direction;
    
  [3] Determine the "Major axis" (x or y) based on the absolute values of dx and dy 
                -> max = (max(|dx|, |dy|)):
    
  [3] Divide `dx` and `dy` by the "Major axis" to get the x and y step 
                -> x_step = dx / max and y_step = dy / max; 
    
  [4] Increment the step to the x1 and y1 repetebly until you reach the x2 or y2
  
```sd
void	ft_bresenhams_alg(t_mlx *win, t_point p1, t_point p2)
{
	float	x_step;
	float	y_step;
	int		max;
	// Calculate step sizes for incremental drawing
	x_step = p2.x - p1.x; // Calculate step size in x direction from p1 to p2
	y_step = p2.y - p1.y; // Calculate step size in y direction from p1 to p2
	
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
```
### 2. Isometric view
Isometric view is a method used in computer graphics to represent three-dimensional (3D) objects in a two-dimensional (2D) space without any foreshortening of the axes. It aims to provide a more natural and intuitive way of visualizing 3D scenes on a flat surface, such as a computer screen or paper. Unlike perspective views that alter the apparent size of objects based on their distance from the viewer, isometric view maintains equal scaling along all three axes (x, y, and z).

**2.1 How to Implement Isometric View**
Implementing isometric view involves transforming 3D coordinates into 2D coordinates using specific mathematical operations.
The isometric projection preserves the angles between the axes (typically 120 degrees) and ensures that objects appear the same size regardless of their distance from the viewer.

**Mathematical Formulation:**
    
1. Use trigonometric functions such as cosine (cos) and sine (sin) to rotate and scale the 3D coordinates to fit the desired projection angle.
2. Adjust the z-coordinate to simulate depth perception, often by subtracting or adding a component based on the angle of projection.
3. Steps to Implement Isometric View:
    - Determine the angle (ang) at which the 3D scene will be projected onto the 2D plane. Typically, this is set to 30 degrees for standard isometric projection.
    - Apply Transformation: For each vertex (x, y, z) of the 3D object:
        - Rotate the x and y coordinates using x' = (x - y) * cos(ang) and y' = (x + y) * sin(ang).
        - Adjust the z-coordinate to simulate depth perception, e.g., y' = y' - z.
```sh
static void	isometric_view(t_point *p, float ang)
{
	p->x = (p->x - p->y) * cos(ang); // Rotate x and y coordinates
	p->y = (p->x + p->y) * sin(ang) - p->z; // Adjust y coordinate and subtract z for depth
}
```
### 3. Rendering and Display
Now we get to apply what we learned so far!!
First lets make a function that will render the images on our window
This first part is simple, we just need to get the map data and create the window
```sh
void	render(t_map *map)
{
	t_mlx	*win;
	win = malloc(sizeof(t_mlx)); // Allocate memory for the window structure
  	set_up_win(win); // Set up the window properties and initial configurations
	win->mlx_connect = mlx_init(); // Initialize connection to the MiniLibX library
	win->mlx_win = mlx_new_window(win->mlx_connect, WIDTH, HEIGHT, "Fdf"); // Create a new window with specified dimensions and title
	win->map = map; // Associate the map data with the window structure
	mlx_loop(win->mlx_connect); // Start the MiniLibX event loop for window interaction
}
```
Now it comes a new `concept`, the subject says we cant draw pixel per pixel on screen so the mlx_put_pixel is of limits to us!

How can we draw the image then? Its simple, we use mlx image:

Remember the t_img struck in the begginig? Its time to fill that struck with the window data. To achieve that we use the `mlx_new_image`, `mlx_get_data_addr` and `mlx_put_image_to_window` funcs.

`mlx_new_image` - Creates a new image (win->img.mlx_img) in memory with dimensions specified by WIDTH and HEIGHT, which serves as a canvas for drawing operations.

`mlx_get_data_addr` - Retrieves the address (addr), bits per pixel (bpp), line length (line_len), and endianness (endian) information of the image (win->img.mlx_img) for direct manipulation of pixel data.

`mlx_put_image_to_window` - Updates the image

```
win->img.mlx_img = mlx_new_image(win->mlx_connect, WIDTH, HEIGHT);
win->img.addr = mlx_get_data_addr(win->img.mlx_img, &win->img.bpp, &win->img.line_len, &win->img.endian);
mlx_put_image_to_window(win->mlx_connect, win->mlx_win, win->img.mlx_img, 0, 0);
```
Another interesting function is the `mlx_loop_hook`, this function is used to set up a loop hook that automatically calls a specified function for continuous rendering or updating of the window content.
```
mlx_loop_hook(win->mlx_connect, &draw, win)
```
We will draw on the new image that we created, and after we draw the entire image, we will update the window. This is similar to how a game works: the entire image is updated as we play, so we don’t see all the pixels being drawn on the screen.

### 3.1 Drawing the pixel

Drawing the exact pixel we want isn't very hard. We just have to locate the pixel we want and change its color. The expression we need to use is:
```
pixel = img->addr + (y * img->line_len + x * (img->bpp / 8))
```
The pixel variable is a char* just like any other string. This means we add the x value to the string to get the pixel we want.

For example, if we want to get the 155th position of a string, we can do it with str + 155. This works exactly the same way when we want to get a specific pixel in the image!

We just need to multiply y by the line length and add x multiplied by the bits per pixel divided by 8 to get the correct memory address of the pixel.

Now we "paint the pixel" -> *(int *)pixel = color;

```
void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(int *)pixel = color;
	}
}
```
# Final touches and key handlers
So we are near the end. We just need to add everything up and apply some key bindings, and we’re done! (I won't paste all the render code here as it is in this folder, so go check it if you need. I tried to place comments to make it easier to read, so have fun browsing.)

The subject says the window must close on the X and when we press the ESQ key, to detect those keys we use the `mlx_key_hook` and `mlx_hook` funcs.
```
mlx_hook(win->mlx_win, KeyPress, KeyPressMask, key handler function name, win)
mlx_key_hook(win->mlx_win, key handler function name, win)
```
Now, in the key handler function, we just need to compare the key pressed. If it matches the key we want (e.g., the Escape key), we close the window or perform any desired action.

Example:
```
int	ft_event_checker(int Key, t_mlx *mlx)
{
	if (Key == XK_Escape)
		ft_cleanup_and_exit(mlx);
	return (0);
}
```
Handling the close event from the window's close button (usually represented by the "X" button) is a bit more complicated. Here is how I managed to do it. As I don't fully understand all the details, I'll just show the code:
```
mlx_hook(win->mlx_win, 17, 0, ft_close, win)
```
Also, I didn't go through it in detail, but don't forget that you need to ensure the program only reads .fdf files and that you have the necessary permissions to open the file!
# Time to make all kind of bonus!

Finally, we arrive at the end! Now, you can add all the bonuses you want. I won't explain any more so you can let your imagination run wild! Okay, just a little tip... You can change the color by multiplying a color factor with the original color. Just do color *= 1.45 and it applies a shade of red! Have FUN! 🎨

# Conclusion
I hope I managed to help you in this project! By following this guide i hope you learned how to:
* Gain a solid understanding of the key concepts and data structures used in the project.
* Properly set up and configure the MiniLibX graphics library to handle window creation and event management.
* Implement functions to read and interpret map data, converting it into a usable format for rendering.
* Use mathematical transformations to implement isometric views and zoom functionality.
* Use Bresenham's algorithm to draw lines and render the wireframe representation of the map.
* mplement key bindings and event handlers to allow for interactive control of the visualization.
* nsure proper resource management and cleanup to avoid memory leaks and ensure smooth execution.
* This guide has provided a step-by-step approach to understanding and implementing each component of the FDF project. By breaking down the tasks and explaining the concepts clearly, I aimed to make this project accessible even for beginners.

### Appendices
I have a txt file that have the links i used during this project, try them if i didnt do a good job during the guide!
