/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:47:56 by tmillot           #+#    #+#             */
/*   Updated: 2024/10/24 19:25:06 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*void to_uppercase(unsigned int index, char c) 
{
    (void)index;
    if (c >= 'a' && c <= 'z')
        c = c - 32;
}

int main(int argc, char **argv)
{
	(void)argc;
	ft_striteri(argv[1], &to_uppercase);
	printf("%s", argv[1]);
}*/