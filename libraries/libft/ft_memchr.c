/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:49:48 by diogosan          #+#    #+#             */
/*   Updated: 2023/09/05 10:49:51 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)src;
	i = 0;
	while (n > i)
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	return ((void *)0);
}
/*
int	main()
{
	char	*ptr;
	char	tweet[] = "ola friend";
	
	ptr = ft_memchr(tweet, 'f', 8);
	
	printf("%s", ptr);
}
*/
