/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:30:59 by diogosan          #+#    #+#             */
/*   Updated: 2024/04/05 16:33:23 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_ft_putnbr_hexa(unsigned int nb, char *base, int fd, int c)
{
	unsigned int	len;

	len = printf_ft_strlen(base);
	if (nb >= len)
	{
		c = printf_ft_putnbr_hexa(nb / len, base, fd, c);
		nb = nb % len;
	}
	if (nb < len)
		c += printf_ft_putchar_fd(base[nb], fd);
	return (c);
}
