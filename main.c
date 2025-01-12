/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:04:40 by thomas            #+#    #+#             */
/*   Updated: 2025/01/12 23:29:21 by thomas           ###   ########.fr       */
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

void	exec_path(char *argv, char **env)
{
	char	**path;
	char	**cmd;
	int		i;

	cmd = ft_split(argv, ' ');
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

void	processus_1(char *in_file, char *cmd, int pipefd[2], char **env)
{
	int	in_file_fd;
	
	in_file_fd = open(in_file, O_RDONLY);
	if (in_file_fd == -1)
	{
		perror("Error during opening the entry file");
		exit(1);
	}
	close(pipefd[0]);
	dup2(in_file_fd, 0);
	dup2(pipefd[1], 1);
	exec_path(cmd, env);
}

void	processus_2(char *out_file, char *cmd, int pipefd[2], char **env)
{
	int	out_file_fd;

	out_file_fd = open(out_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (out_file_fd == -1)
		perror("Error during opening the entry file");
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	dup2(out_file_fd, 1);
	exec_path(cmd, env);
}

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		perror("Entry file1 cmd1 cmd2 file2");
	if (pipe(pipefd) == -1)
		perror("Error to pipe");
	pid1 = fork();
	if (pid1 == -1)
        perror("Error to fork");
	else if (pid1 == 0)
		processus_1(argv[1], argv[2], pipefd, env);
	pid2 = fork();
	if (pid2 == -1)
        perror("Error to fork");
	else if (pid2 == 0)
		processus_2(argv[4], argv[3], pipefd, env);
	close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}

	// int		std_in = 0;
	// int 	std_out = 0;
	// int		pipefd[2];
	// pid_t	pid1;
	// pid_t	pid2;
	
	// if (argc != 5)
	// 	exit(1);
	// pid1 = fork();
	// pid2 = fork();
	// pipefd[0] = std_in;
	// pipefd[1] = std_out;
	// pipe(pipefd);
	// if (pid1 == 0)
	// {
	// 	std_in = open(argv[1], O_RDONLY);
	// 	dup2(std_in, 0);
	// 	dup2(pipefd[1], 1);
	// 	exec_path(argv[2], env);
	// 	close(pipefd[0]);
	// 	close(std_in);
	// }
	// if (pid2 == 0)
	// {
	// 	std_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// 	dup2(pipefd[0], 0);
	// 	dup2(std_out, 1);
	// 	close(pipefd[1]);
    //     close(std_out);
    //     exec_path(argv[3], env);
	// }
	// close(pipefd[0]);
    // close(pipefd[1]);
    // waitpid(pid1, NULL, 0);
    // waitpid(pid2, NULL, 0);

	
	// if (argc > 4)
	// {
	// 	if (pid == 0)
	// 	{
	// 		if (access(argv[1], F_OK) == 0)
	// 		{
	// 			std_in = open(argv[1], O_RDONLY);
	// 			dup2(std_in, 0);
	// 			exec_path(argv[2], env);
	// 			close(0);	
	// 		}
	// 	}
	// 	else 
	// 	{
	// 		std_out = open(argv[4], O_WRONLY | O_CREAT, 0644);
	// 		dup2(std_out, 1);
	// 		exec_path(argv[3], env);
	// 		close(1);
	// 	}
	// pour la fonction pipe ls fd[1] est pour l'ecriture et le fd[0] pour la lecture}