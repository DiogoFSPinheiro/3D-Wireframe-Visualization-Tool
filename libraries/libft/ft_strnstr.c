/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:21:34 by diogosan          #+#    #+#             */
/*   Updated: 2023/10/11 11:21:48 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t t)
{
	size_t	n;

	if (*little == 0)
		return ((char *)big);
	n = ft_strlen(little);
	if (t == 0)
		return (0);
	while (*big && n <= t)
	{
		if (*big == *little && ft_strncmp(big, little, n) == 0)
			return ((char *)big);
		big++;
		t--;
	}
	return (NULL);
}
/*int	main()
{
	char	str[] = "Indo eu, indo eu";
	char	str1[] = "indo";
	ft_putendl_fd(ft_strnstr(str, str1, ft_strlen(str)), 1);
}*/
