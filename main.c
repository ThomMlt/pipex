/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:04:40 by thomas            #+#    #+#             */
/*   Updated: 2025/01/09 16:40:45 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_path(char **env)
{
	char	*path;
	int		i;

	path = "PATH";
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(path, env[i], 4) ==  0)
			return (i);
		i++;
	}
	return (-1);
}

void	exec_path(char **argv, char **env)
{
	char	**path;
	char	**cmd;
	int		i;

	cmd = ft_split(argv[2], ' ');
	cmd[0] = ft_strjoin("/", cmd[0]);
	path = ft_split(env[find_path(env)], ':');
	i = 0;
	while (path[i] != NULL)
	{
		path[i] = ft_strjoin(path[i], cmd[0]);
		if (access(path[i], F_OK | X_OK) == 0)
		{
			execve(path[i], cmd, env);
		}
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	// if (argc > 4)
	// {
	// 	char **tab = ft_split(argv[2], ' ');
	// 	while ( != NULL)
	// 	{
	// 		if (access(argv[1], F_OK) == -1)
	// 			ft_printf("No such file or directory : %s", argv[1]);
	// 		ft_printf("%d", execve(tab[0], tab, env));
	// 		i++;
	// 	}
	// }
	int	std_in;
	std_in = open(argv[1], O_RDONLY);
	dup2(std_in, 0);
	(void)argc;
	exec_path(argv, env);
}

/* donc faire l'executable avec execve faire un str join avec la premiere parti de la commande
sur le split des commande et savoir si on a acces a ce dossier et qu'on est la version X et qu'il
existe*/