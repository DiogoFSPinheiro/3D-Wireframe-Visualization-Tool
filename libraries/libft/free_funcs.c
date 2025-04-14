/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:14:32 by diogosan          #+#    #+#             */
/*   Updated: 2024/05/13 15:53:15 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_args(char **numbers)
{
	int	i;

	i = 0;
	if (!numbers || !*numbers)
		return ;
	while (numbers[i] != NULL)
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}
