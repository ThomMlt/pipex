/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:17:22 by tmillot           #+#    #+#             */
/*   Updated: 2024/10/26 19:45:09 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			count++;
		}
	}
	return (count);
}

static char	*copy_str(const char *s, int start, int end)
{
	char	*str;

	str = ft_substr(s, start, (end - start));
	return (str);
}

static void	free_tab(char **tab, int y)
{
	while (y >= 0)
	{
		free(tab[y]);
		y--;
	}
	free(tab);
}

static int	ft_copy_str_tab(char **tab, const char *s, char c, int start)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (i > start)
		{
			tab[y] = copy_str(s, start, i);
			if (!tab[y])
			{
				free_tab(tab, y - 1);
				return (0);
			}
			y++;
		}
	}
	tab[y] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (!ft_copy_str_tab(tab, s, c, 0))
		return (NULL);
	return (tab);
}

/*int main(int argc, char **argv)
{
	(void)argc;
	char **tab = ft_split(argv[1], argv[2][0]);
 	int i = 0;
	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		i++;
	}
}*/
