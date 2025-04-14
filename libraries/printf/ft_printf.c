/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:15:39 by diogosan          #+#    #+#             */
/*   Updated: 2024/05/13 15:08:42 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char type, va_list args)
{
	if (type == 'c')
		return (printf_ft_putchar_fd(va_arg(args, int), 1));
	else if (type == 's')
		return (printf_ft_putstr_fd(va_arg(args, char *), 1));
	else if (type == 'd' || type == 'i')
		return (printf_ft_putnbr_fd(va_arg(args, int), 1, 0));
	else if (type == 'x')
		return (printf_ft_putnbr_hexa(va_arg(args, int),
				"0123456789abcdef", 1, 0));
	else if (type == 'X')
		return (printf_ft_putnbr_hexa(va_arg(args, int),
				"0123456789ABCDEF", 1, 0));
	else if (type == 'p')
		return (printf_ft_putnbr_ptr(va_arg(args, unsigned long long), 1));
	else if (type == 'u')
		return (printf_ft_putnbr_fd_u(va_arg(args, int), 1, 0));
	else if (type == '%')
		return (printf_ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			len += print_format(*(++format), args);
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (len);
}

int	ft_println(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			len += print_format(*(++format), args);
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(args);
	write(1, "\n", 1);
	return (len);
}
/*
int	main()
{
    //char *ptr= "ola bro";
    int	i;
    int	j;
    
    i = 0;
    j = 0;
    i = ft_printf("o char é: %p\n", "ola123");
    j = printf("o char é: %p\n", "ola123");
    printf("o char é: %d\n", i);
    printf("o char é: %d\n", j);
    ft_printf("o nbr é: %i\n", 12345);
    printf("o nbr é: %i\n", 12345);
    ft_printf("o str é: %s\n", "oh baby a triple");
    printf("o str é: %s\n", "oh baby a triple");
    ft_printf("o nbr em hexa é: %x\n", 16345);
    printf("o nbr em hexa é: %x\n", 16345);
    ft_printf("o nbr em hexa é: %X\n", 16345);
    printf("o nbr em hexa é: %X\n", 16345);
    ft_printf("toma um %i %%\n", 100);
    printf("toma um %i %%\n", 100);
    printf("toma um %p\n", &ptr);

    return (0);
}
*/
