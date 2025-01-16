/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:48:21 by tmillot           #+#    #+#             */
/*   Updated: 2025/01/16 15:19:19 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_tab_bonus(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_all_bonus(char **tab1, char **tab2)
{
	ft_free_tab(tab1);
	ft_free_tab(tab2);
}

void	exit_error_bonus(const char *str)
{
	perror(str);
	exit(1);
}

int	find_path_bonus(char **env)
{
	char	*path;
	int		i;

	path = "PATH";
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(path, env[i], 4) == 0)
			return (i);
		i++;
	}
	return (-1);
}
