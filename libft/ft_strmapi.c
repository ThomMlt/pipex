/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:23:26 by tmillot           #+#    #+#             */
/*   Updated: 2024/10/26 18:00:27 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*str;
	unsigned int		i;

	i = 0;
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!s || !f)
		return (0);
	if (!str)
		return (0);
	while (s[i] != '\0')
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*char to_uppercase(unsigned int index, char c) 
{
    (void)index;
    if (c >= 'a' && c <= 'z')
        return (c - 32); 
    return c;
}

int main(int argc, char **argv)
{
	(void)argc;
	char *dest = ft_strmapi(argv[1], to_uppercase);
	printf("%s", dest);
}*/
