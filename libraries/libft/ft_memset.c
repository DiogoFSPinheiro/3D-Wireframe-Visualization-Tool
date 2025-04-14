/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:49:48 by diogosan          #+#    #+#             */
/*   Updated: 2023/09/05 10:49:51 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		p[i] = x;
		i++;
	}
	return (ptr);
}
/*
int main() 
{ 
    char str[40] = "GeeksForGeeks is for programming geeks."; 
    char str1[40] = "GeeksForGeeks is for programming geeks.";
    //memset(str + 13, '.', 8*sizeof(char)); 
    ft_memset(str1 + 13, '.', 8*sizeof(char));
    
  
    printf("After memset():  %s\n", str); 
    printf("After memset():  %s", str1); 
    return 0; 
}
*/
