/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:16:39 by tmillot           #+#    #+#             */
/*   Updated: 2025/01/16 16:51:46 by tmillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../sources/libft/libft.h"
# include "../sources/ft_printf/ft_printf.h"
# include "../sources/get_next_line/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

# define ERR_PIPE		"error during pipe creation"
# define ERR_FORK		"error during fork"
# define ERR_OPEN		"Error opening a file"
# define ERR_DUP2		"Error redirecting file descriptors"
# define ERR_EXEC		"Command execution error"
# define ERR_ARGC		"argument not valid. Entry file1 cmd1 cmd2 file2"
# define ERR_ARGC_BONUS	"argument not valid. Entry file1 cmd1 ... cmdn file2"
# define ERR_HERE_DOC	"entry em limiter : ere_doc LIMITER cmd cmd1 file"

void	ft_free_tab(char **tab);
void	free_all(char **tab1, char **tab2);
void	exit_error(const char *str);
void	exit_error_bonus(const char *str);
int		find_path(char **env);
int		find_path_bonus(char **env);
void	exec_path(char *argv, char **env);
void	processus_1(char *in_file, char *cmd, int pipefd[2], char **env);
void	processus_2(char *out_file, char *cmd, int pipefd[2], char **env);
int		if_limiter(char *line, char *limiter);

#endif