/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:41:28 by tmillot           #+#    #+#             */
/*   Updated: 2024/10/17 11:33:50 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;

	dest = (unsigned char *)s;
	while (n > 0)
	{
		*dest++ = 0;
		n--;
	}
}

/*int main(int argc, char **argv)
{
	(void)argc;
	char str[100];
	strncpy(str, argv[1], sizeof(str));
	str[sizeof(str) - 1] = '\0';

	printf("Original: %s\n", str); 
	size_t i = 0;
	size_t len = ft_strlen(str);
	ft_bzero(str, 2);
	while (i < len)
	{
		printf("%c", str[i]);
		i++;
	}
}*/
