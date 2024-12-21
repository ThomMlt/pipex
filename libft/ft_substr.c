/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:53:10 by tmillot           #+#    #+#             */
/*   Updated: 2024/10/22 13:27:08 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

/*int main(void)
{
	char *s = "hello world";
	char *sub = ft_substr(s, 1, 5);
	char *test = ft_calloc(1, sizeof(char));
	printf("%s\n", sub);
	printf("%s", test);
}*/
