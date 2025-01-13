/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:28:41 by tmillot           #+#    #+#             */
/*   Updated: 2024/10/27 08:40:01 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	length_dest;

	i = 0;
	length_dest = 0;
	while (dest[length_dest] != '\0')
	{
		length_dest++;
	}
	while (src[i] != '\0')
	{
		dest[length_dest + i] = src[i];
		i++;
	}
	dest[length_dest + i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!str)
		return (0);
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	return (str);
}

/*int main(int argc, char **argv)
{
	(void)argc;
	char *str = ft_strjoin(argv[1], argv[2]);
	printf("%s", str);
}*/