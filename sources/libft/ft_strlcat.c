/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:17:03 by tmillot           #+#    #+#             */
/*   Updated: 2024/10/18 14:30:13 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (size <= len_dest)
		return (size + len_src);
	while (i < (size - len_dest - 1) && src[i] != '\0')
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}

/*#include <bsd/string.h>
int main(int argc, char **argv)
{
	(void)argc;
	printf("origin dest : %s\n origin src : %s\n", argv[1], argv[2]);
	printf("%zu\n", ft_strlcat(argv[1], argv[2], atoi(argv[3])));
	printf("after ft_strlcat : %s", argv[1]);
}*/