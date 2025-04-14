/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:00:02 by diogosan          #+#    #+#             */
/*   Updated: 2024/04/05 16:33:41 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_ft_putstr_fd(char *s, int fd)
{
	int	c;

	if (!s)
		s = "(null)";
	c = 0;
	while (s[c])
	{
		write(fd, &s[c], 1);
		c++;
	}
	return (c);
}
