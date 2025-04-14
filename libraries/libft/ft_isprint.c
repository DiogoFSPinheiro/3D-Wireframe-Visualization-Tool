/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:07:28 by diogosan          #+#    #+#             */
/*   Updated: 2023/09/02 15:07:30 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}
/*

int main()
{
	int	output;
	char str[] = "OLA";
	char err[] = "";

	output = ft_str_is_printable( str);
	printf("%d\n%d", output ,ft_str_is_printable( err));
	
	
	
}
*/
