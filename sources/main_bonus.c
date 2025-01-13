/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:04:40 by thomas            #+#    #+#             */
/*   Updated: 2025/01/13 17:53:36 by tmillot          ###   ########.fr       */
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

// void	processus_1(char *in_file, char *cmd, int pipefd[2], char **env)
// {
// 	int	in_file_fd;

// 	in_file_fd = open(in_file, O_RDONLY);
// 	if (in_file_fd == -1)
// 	{
// 		perror("Error during opening the entry file");
// 		exit(1);
// 	}
// 	close(pipefd[0]);
// 	dup2(in_file_fd, 0);
// 	dup2(pipefd[1], 1);
// 	exec_path(cmd, env);
// }

// void	processus_2(char *out_file, char *cmd, int pipefd[2], char **env)
// {
// 	int	out_file_fd;

// 	out_file_fd = open(out_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
// 	if (out_file_fd == -1)
// 		perror("Error during opening the entry file");
// 	close(pipefd[1]);
// 	dup2(pipefd[0], 0);
// 	dup2(out_file_fd, 1);
// 	exec_path(cmd, env);
// }

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
		line = get_next_line(0);
		while (line != NULL)
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(0);
			write(pipefd[1], line, ft_strlen(line));
			line = get_next_line(0);
		}
	}
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	wait(NULL);
}

void	ft_process(char *cmd, char **env)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		perror("Pipe");
	pid = fork();
	if (pid == -1)
		perror("fork");
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		exec_path(cmd, env);
	}
	close(pipefd[0]);
	dup2(pipefd[0], 0);
	waitpid(pid, NULL, 0);
}

int	main(int argc, char **argv, char **env)
{
	int	out_file;
	int	in_file;
	int i;
	
	if (argc < 5)
		perror("Entry file1 cmd1 cmd2 file2");
	printf("argc = %d\n", argc);
	printf("argv 6 = %s\n", argv[argc-1]);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i = 3;
		ft_here_doc(argv[2]);
		out_file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
	}
	else
	{
		i = 2;
		out_file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		in_file = open(argv[1], O_RDONLY);
		dup2(in_file, 0);
	}
	while (i < argc - 2)
		ft_process(argv[i++], env);
	dup2(out_file, 1);
	ft_process(argv[argc - 2], env);
}
	// int		pipefd[2];
	// pid_t	pid1;
	// pid_t	pid2;
	// if (argc != 5)
	// 	perror("Entry file1 cmd1 cmd2 file2");
	// if (pipe(pipefd) == -1)
	// 	perror("Error to pipe");
	// pid1 = fork();
	// if (pid1 == -1)
	// 	perror("Error to fork");
	// else if (pid1 == 0)
	// 	processus_1(argv[1], argv[2], pipefd, env);
	// pid2 = fork();
	// if (pid2 == -1)
	// 	perror("Error to fork");
	// else if (pid2 == 0)
	// 	processus_2(argv[4], argv[3], pipefd, env);
	// close(pipefd[0]);
	// close(pipefd[1]);
	// waitpid(pid1, NULL, 0);
	// waitpid(pid2, NULL, 0);
