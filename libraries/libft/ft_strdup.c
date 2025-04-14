/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:49:48 by diogosan          #+#    #+#             */
/*   Updated: 2023/09/05 10:49:51 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	int		c;
	char	*dest;

	dest = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	if (!dest)
		return (0);
	c = 0;
	while (src[c])
	{
		dest[c] = src[c];
		c++;
	}
	dest[c] = '\0';
	return (dest);
}
/*
int	main(int t, char **v)
{
	char	*show;
	int	c;
	char	*str = v[1];
	
	t = 0; 
	
	show = ft_strdup(str);
	c = 0;
	while (show[c])
	{
		write (1, &show[c],1);
		c++;
	}
}
*/
