/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:49:48 by diogosan          #+#    #+#             */
/*   Updated: 2023/09/05 10:49:51 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
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
