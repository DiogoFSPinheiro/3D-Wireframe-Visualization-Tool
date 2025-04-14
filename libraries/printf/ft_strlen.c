/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:49:48 by diogosan          #+#    #+#             */
/*   Updated: 2024/04/05 16:33:45 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	printf_ft_strlen(const char *str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		c++;
	}
	return (c);
}

/*
int	main()
{
	char *str = "gajas boas";
	

	printf("%d",ft_strlen(str));
}
*/
