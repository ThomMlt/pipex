/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:04:40 by thomas            #+#    #+#             */
/*   Updated: 2025/01/16 11:43:16 by tmillot          ###   ########.fr       */
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
	i = 0;
	while (path[i] != NULL)
	{
		path_cmd = ft_strjoin(path[i], cmd_slash);
		if (access(path_cmd, F_OK | X_OK) == 0)
		{
			ft_free_tab(path);
			free(cmd_slash);
			execve(path_cmd, cmd, env);
			free_all(cmd, &path_cmd);
		}
		free(path_cmd);
		i++;
	}
	free_all(path, cmd);
	free(cmd_slash);
}

void	ft_here_doc(char *limiter)
{
	int		pipefd[2];
	pid_t	processus;
	char	*line;

	if (pipe(pipefd) == -1)
		perror("Error during make pipe");
	processus = fork();
	if (processus == 0)
	{
		close(pipefd[0]);
		while ((line = get_next_line(0)) != NULL)
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			{
				free(line);
				exit(0);
			}
			write(pipefd[1], line, ft_strlen(line));
			free(line);
		}
	}
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	wait(NULL);
}

void	ft_process(char *cmd, char **env, int in_fd, int out_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror("fork");
	if (pid == 0)
    {
        if (in_fd != STDIN_FILENO)
        {
            dup2(in_fd, STDIN_FILENO);
            close(in_fd);
        }
        if (out_fd != STDOUT_FILENO)
        {
            dup2(out_fd, STDOUT_FILENO);
            close(out_fd);
        }
        exec_path(cmd, env);
        perror("Command not found");
    }
}

void	handle_pipes(int argc, char **argv, char **env, int start_index)
{
	int	i;
	int fd[2];
	int	prev_fd;
	
	prev_fd = STDIN_FILENO;
	i = start_index;
	while (i < (argc - 2))
	{
		if (pipe(fd) == -1)
			exit(0); // faire une fonction exit error 
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

int	main(int argc, char **argv, char **env)
{
	int	out_file;
	int	in_file;
	int start_index;
	
	if (argc < 5)
		perror("Entry file1 cmd1 cmd2 file2");
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		start_index = 3;
		ft_here_doc(argv[2]);
		out_file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
	}
	else
	{
		start_index = 2;
		out_file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		in_file = open(argv[1], O_RDONLY);
		dup2(in_file, STDIN_FILENO);
	}
	dup2(out_file, STDOUT_FILENO);
    close(out_file);
    handle_pipes(argc, argv, env, start_index);
}
