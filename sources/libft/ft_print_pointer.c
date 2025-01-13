/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:39:05 by toto              #+#    #+#             */
/*   Updated: 2024/11/23 16:42:46 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_pointer(unsigned long ptr, int *count)
{
	const char		*hexa;
	char			stock[16];
	int				i;

	hexa = "0123456789abcdef";
	i = 0;
	if (!ptr)
		(*count) += write(1, "(nil)", 5);
	if (ptr != 0)
	{
		while (ptr > 0)
		{
			stock[i++] = hexa[ptr % 16];
			ptr = ptr / 16;
		}
		(*count) += write(1, "0x", 2);
		while (i > 0)
			(*count) += write(1, &stock[--i], 1);
	}
}
