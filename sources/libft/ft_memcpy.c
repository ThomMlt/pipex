/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:24:34 by tmillot           #+#    #+#             */
/*   Updated: 2024/10/16 13:55:22 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		*d++ = *s++;
		n--;
	}
	return (dest);
}

/*int main(int argc, char **argv)
{
	(void)argc;
	printf("dest origin :%s\n source origin :%s\n", argv[1], argv[2]);
	ft_memcpy(argv[1], argv[2], atoi(argv[3]));
	printf("dest after ft_memcpy : %s\n", argv[1]);
}*/
