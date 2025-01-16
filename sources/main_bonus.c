/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:04:40 by thomas            #+#    #+#             */
/*   Updated: 2025/01/16 16:51:55 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exec_path(char *argv, char **env)
{
	char	**path;
	char	**cmd;
	char	*cmd_slash;
	char	*path_cmd;
	int		i;

	path = ft_split(env[find_path_bonus(env)], ':');
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

void	ft_here_doc(char *limiter)
{
	int		fd[2];
	pid_t	processus;
	char	*line;

	if (pipe(fd) == -1)
		exit_error_bonus(ERR_PIPE);
	processus = fork();
	if (processus == -1)
		exit_error_bonus(ERR_FORK);
	if (processus == 0)
	{
		close(fd[0]);
		line = get_next_line(0);
		while (line != NULL)
		{
			if (if_limiter(line, limiter) == 0)
				return (free(line), exit(1));
			write(fd[1], line, ft_strlen(line));
			free(line);
			line = get_next_line(0);
		}
	}
	if (close(fd[1]) == -1 || dup2(fd[0], 0) == -1 || close(fd[0]) == -1)
		exit_error_bonus(ERR_DUP2);
	wait(NULL);
}

void	ft_process(char *cmd, char **env, int in_fd, int out_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_error_bonus(ERR_FORK);
	if (pid == 0)
	{
		if (in_fd != STDIN_FILENO)
		{
			if (dup2(in_fd, STDIN_FILENO) == -1)
				exit_error_bonus(ERR_DUP2);
			close(in_fd);
		}
		if (out_fd != STDOUT_FILENO)
		{
			if (dup2(out_fd, STDOUT_FILENO) == -1)
				exit_error_bonus(ERR_DUP2);
			close(out_fd);
		}
		exec_path(cmd, env);
		exit_error_bonus(ERR_EXEC);
	}
}

void	handle_pipes(int argc, char **argv, char **env, int start_index)
{
	int	i;
	int	fd[2];
	int	prev_fd;

	prev_fd = STDIN_FILENO;
	i = start_index;
	while (i < (argc - 2))
	{
		if (pipe(fd) == -1)
			exit_error_bonus(ERR_PIPE);
		ft_process(argv[i], env, prev_fd, fd[1]);
		close(fd[1]);
		if (prev_fd != STDIN_FILENO)
			close(prev_fd);
		prev_fd = fd[0];
		i++;
	}
	ft_process(argv[i], env, prev_fd, STDOUT_FILENO);
	if (prev_fd != STDIN_FILENO)
		close(prev_fd);
}

int	main(int ac, char **av, char **env)
{
	int	out_fd;
	int	in_fd;
	int	start_index;

	if (ac < 5)
		exit_error_bonus(ERR_ARGC_BONUS);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		start_index = 3;
		ft_here_doc(av[2]);
		out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
	}
	else
	{
		start_index = 2;
		in_fd = open(av[1], O_RDONLY | F_OK);
		if (in_fd != -1 && dup2(in_fd, STDIN_FILENO) == -1)
			exit_error_bonus(ERR_DUP2);
		close(in_fd);
		out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	}
	if (out_fd == -1 || dup2(out_fd, STDOUT_FILENO) == -1)
		exit_error_bonus(ERR_DUP2);
	close(out_fd);
	handle_pipes(ac, av, env, start_index);
}
