/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:41:01 by diogosan          #+#    #+#             */
/*   Updated: 2023/11/09 11:41:03 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		size;
	int		c;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	str = malloc(sizeof(char) * (size +1));
	if (!str)
		return (NULL);
	c = 0;
	while (s[c])
	{
		str[c] = (*f)(c, s[c]);
		c++;
	}
	str[c] = 0;
	return (str);
}
