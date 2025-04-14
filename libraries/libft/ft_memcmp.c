/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:23:05 by diogosan          #+#    #+#             */
/*   Updated: 2023/09/03 12:23:24 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned int	c;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	c = 0;
	while (c < n)
	{
		if (s1[c] != s2[c])
		{
			return ((int)s1[c] - (int)s2[c]);
		}
		c++;
	}
	return (0);
}
/*
int main() 
{ 
	char str[40] = "GeeksForGeeks dif"; 
	char str1[40] = "GeeksForGeeks here";
	int	val;

	val = ft_memcmp(str, str1, 16);
	printf("%d\n", val); 

}
*/
