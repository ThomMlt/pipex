/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:00:45 by tmillot           #+#    #+#             */
/*   Updated: 2024/10/16 16:38:38 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (d > s)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	return (dest);
}

/*int main(int argc, char **argv)
{
	(void)argc;
	printf("dest origin :%s\n source origin :%s\n", argv[1], argv[2]);
	ft_memmove(argv[1], argv[2], atoi(argv[3]));
	printf("dest after ft_memmove : %s\n", argv[1]);
}*/
