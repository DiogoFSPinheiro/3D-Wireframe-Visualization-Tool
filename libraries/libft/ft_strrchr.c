/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:49:48 by diogosan          #+#    #+#             */
/*   Updated: 2023/09/05 10:49:51 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*str)
	{
		if (*str == (unsigned char)c)
			ptr = (char *)str;
		str++;
	}
	if ((char)c == 0)
		return ((char *)str);
	return (ptr);
}
/*
int	main()
{
	char	*ptr;
	char	tweet[] = "ola hfrihehnd";
	
	ptr = ft_strrchr(tweet, 'h');
	
	printf("%s", ptr);
}
*/
