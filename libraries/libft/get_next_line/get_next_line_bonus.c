/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:02:44 by diogosan          #+#    #+#             */
/*   Updated: 2023/12/21 11:03:10 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

char	*read_file(int fd, char *stack)
{
	char	*buffer;
	int		fim;

	if (!stack)
		stack = ft_calloc(1, 1);
	buffer = ft_calloc_nl(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	fim = 1;
	while (fim != 0)
	{
		fim = read(fd, buffer, BUFFER_SIZE);
		if (fim == -1)
			break ;
		buffer[fim] = '\0';
		stack = str_join(stack, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	if (!*stack || fim == -1)
		return (free(stack), NULL);
	return (stack);
}

char	*polish(char *stack)
{
	size_t		c;
	size_t		i;
	char		*polished;

	c = 0;
	while (stack[c] && stack[c] != '\n')
		c++;
	if (!stack[c])
		return (free(stack), NULL);
	polished = ft_calloc_nl(sizeof(char), (str_len(stack) - c + 1));
	if (stack[c] == '\n')
		c++;
	i = 0;
	while (stack[c + i])
	{
		polished[i] = stack[c + i];
		i++;
	}
	polished[i] = '\0';
	free(stack);
	return (polished);
}

char	*get_end_line(char *stack)
{
	size_t		c;
	size_t		i;
	char		*linha;

	c = 0;
	if (!stack[c])
		return (NULL);
	while (stack[c] && stack[c] != '\n')
		c++;
	i = 0;
	linha = ft_calloc_nl(sizeof(char *), c + 1);
	while (c >= i)
	{
		linha[i] = stack[i];
		i++;
	}
	linha[i] = '\0';
	return (linha);
}

char	*get_next_line(int fd)
{
	static char	*stack[FOPEN_MAX];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	stack[fd] = read_file(fd, stack[fd]);
	if (!stack[fd])
		return (NULL);
	line = get_end_line(stack[fd]);
	stack[fd] = polish(stack[fd]);
	return (line);
}
