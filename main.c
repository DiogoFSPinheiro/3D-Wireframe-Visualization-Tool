/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:53:53 by diogosan          #+#    #+#             */
/*   Updated: 2024/06/20 09:49:23 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	char	*name;

	name = argv[1];
	if (argc == 2)
	{
		if (ft_fdf_check(name))
		{
			map = ft_convert_data(argv[1]);
			render(map);
		}
		else
			write(2, "Error -> Wrong name format\n", 28);
	}
	else
		write(2, "Error -> Too many, too few arguments\n", 38);
	return (0);
}

void	free_map(t_map *map)
{
	int	c;

	c = 0;
	while (map->height > c)
	{
		free(map->coord[c]);
		c++;
	}
	free(map->coord);
	free(map);
}

void	print_map(t_map	*map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map->height > y)
	{
		while (map->width > x)
		{
			ft_printf("%i ", map->coord[y][x].z);
			x++;
		}
		write(1, "\n", 1);
		x = 0;
		y++;
	}
}
