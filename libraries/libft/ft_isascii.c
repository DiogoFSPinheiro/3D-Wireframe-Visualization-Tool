/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:40:08 by diogosan          #+#    #+#             */
/*   Updated: 2023/09/02 14:40:12 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c <= 127 && c >= 0);
}
/*
int main()
{
	int	output;
	char str[] = "123";
	char err[] = "ola 2 peps";
	output = ft_str_is_numeric( str);
	printf("%d\n%d", output ,ft_str_is_numeric( err));
	
	
	
}
*/
