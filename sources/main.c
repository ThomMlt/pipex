/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:04:40 by thomas            #+#    #+#             */
/*   Updated: 2025/01/16 14:00:55 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	find_path(char **env)
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

void	exec_path(char *argv, char **env)
{
	char	**path;
	char	**cmd;
	char	*cmd_slash;
	char	*path_cmd;
	int		i;

	path = ft_split(env[find_path(env)], ':');
	cmd = ft_split(argv, ' ');
	cmd_slash = ft_strjoin("/", *cmd);
	i = -1;
	while (path[++i] != NULL)
	{
		path_cmd = ft_strjoin(path[i], cmd_slash);
		if (access(path_cmd, F_OK | X_OK) == 0)
		{
			ft_free_tab(path);
			free(cmd_slash);
			execve(path_cmd, cmd, env);
			return (ft_free_tab(cmd), free(path_cmd), exit_error(ERR_EXEC));
		}
		free(path_cmd);
	}
	free_all(path, cmd);
	free(cmd_slash);
	exit_error(ERR_EXEC);
}

void	processus_1(char *in_file, char *cmd, int pipefd[2], char **env)
{
	int	in_file_fd;

	in_file_fd = open(in_file, O_RDONLY);
	if (in_file_fd == -1)
		exit_error(ERR_OPEN);
	close(pipefd[0]);
	if (dup2(in_file_fd, STDIN_FILENO) == -1
		|| dup2(pipefd[1], STDOUT_FILENO) == -1)
		exit_error(ERR_DUP2);
	close(in_file_fd);
	exec_path(cmd, env);
}

void	processus_2(char *out_file, char *cmd, int pipefd[2], char **env)
{
	int	out_file_fd;

	out_file_fd = open(out_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (out_file_fd == -1)
		exit_error(ERR_OPEN);
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1
		|| dup2(out_file_fd, STDOUT_FILENO) == -1)
		exit_error(ERR_DUP2);
	close(out_file_fd);
	exec_path(cmd, env);
}

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		exit_error(ERR_ARGC);
	if (pipe(pipefd) == -1)
		exit_error(ERR_PIPE);
	pid1 = fork();
	if (pid1 == -1)
		exit_error(ERR_FORK);
	else if (pid1 == 0)
		processus_1(argv[1], argv[2], pipefd, env);
	pid2 = fork();
	if (pid2 == -1)
		exit_error(ERR_FORK);
	else if (pid2 == 0)
		processus_2(argv[4], argv[3], pipefd, env);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
