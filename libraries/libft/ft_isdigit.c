/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:40:08 by diogosan          #+#    #+#             */
/*   Updated: 2023/09/02 14:40:12 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
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
