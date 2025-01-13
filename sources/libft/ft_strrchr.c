/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:27:27 by tmillot           #+#    #+#             */
/*   Updated: 2024/10/26 15:00:23 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (s[len] != (char)c && len >= 0)
		len--;
	if (s[len] == (char)c)
		return ((char *)&s[len]);
	return (NULL);
}

/*int main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n", strrchr(argv[1], argv[2][0]));
	printf("%s", ft_strrchr(argv[1], argv[2][0]));
}*/