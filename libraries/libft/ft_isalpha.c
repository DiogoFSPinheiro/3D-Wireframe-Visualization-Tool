/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:32:21 by diogosan          #+#    #+#             */
/*   Updated: 2023/09/02 12:35:10 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
		return (0);
	return (1);
}
/*
int main()
{
	int	output;
	char ok = '*';
	char err = '5';
	

	output = ft_isalpha( ok);
	printf("%d\n%d", output ,ft_isalpha( err));
	
	
	
}
*/
