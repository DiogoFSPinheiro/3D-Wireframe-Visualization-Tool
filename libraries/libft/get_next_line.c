/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:28:18 by diogosan          #+#    #+#             */
/*   Updated: 2024/06/17 19:28:17 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file(int fd, char *stack)
{
	char	*buffer;
	int		fim;

	if (!stack)
		stack = ft_calloc_nl(1, 1);
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
	static char	*stack;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stack = read_file(fd, stack);
	if (!stack)
		return (NULL);
	line = get_end_line(stack);
	stack = polish(stack);
	return (line);
}
