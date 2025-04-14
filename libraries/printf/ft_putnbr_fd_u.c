/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:20:05 by diogosan          #+#    #+#             */
/*   Updated: 2024/05/13 15:08:13 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_ft_putnbr_fd_u(unsigned int n, int fd, int c)
{
	if (n <= 0)
	{
		c += printf_ft_putchar_fd('-', fd);
		n = -n;
	}
	while (n > 9)
	{
		c = printf_ft_putnbr_fd(n / 10, fd, c);
		n = n % 10;
	}
	if (n < 10)
		c += printf_ft_putchar_fd(n + 48, fd);
	return (c);
}
