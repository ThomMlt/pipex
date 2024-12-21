/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:16:33 by toto              #+#    #+#             */
/*   Updated: 2024/11/23 16:43:35 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_count(char *str, int *count)
{
	int	i;

	i = 0;
	if (str == NULL)
		(*count) += write(1, "(null)", 6);
	while (str != NULL && str[i] != '\0')
	{
		(*count) += write(1, &str[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
