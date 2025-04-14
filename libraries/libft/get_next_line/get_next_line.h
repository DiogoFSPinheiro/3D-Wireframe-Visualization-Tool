/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:59:24 by diogosan          #+#    #+#             */
/*   Updated: 2024/06/19 18:09:26 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	ft_bzero(void *ptr, size_t n);
int		str_len(const char *str);
void	*ft_calloc_nl(size_t n, size_t size);
char	*str_join(char *stack, char *buffer);
char	*read_file(int fd, char *stack);
char	*polish(char *stack);
char	*get_next_line(int fd);
char	*get_end_line(char *stack);
char	*ft_strchr(const char *str, int c);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 39
# endif

#endif
