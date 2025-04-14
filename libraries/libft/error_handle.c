/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:51:50 by diogosan          #+#    #+#             */
/*   Updated: 2024/05/21 14:38:16 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_perror_exit(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(STDERR_FILENO, str, len);
	exit(EXIT_FAILURE);
}
