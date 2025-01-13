/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:17:43 by tmillot           #+#    #+#             */
/*   Updated: 2024/10/16 17:30:03 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dest;

	dest = (unsigned char *)s;
	while (n > 0)
	{
		*dest++ = (unsigned char)c;
		n--;
	}
	return (s);
}

/*int main(int argc, char **argv)
{
	(void)argc;
	ft_memset(argv[1], argv[2][0], 5);
	printf("%s", argv[1]);
}*/