/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:16:39 by tmillot           #+#    #+#             */
/*   Updated: 2025/01/13 15:26:11 by tmillot          ###   ########.fr       */
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

void	ft_free_tab(char **tab);
void	free_all(char **tab1, char **tab2);
int		find_path(char **env);
void	exec_path(char *argv, char **env);
void	processus_1(char *in_file, char *cmd, int pipefd[2], char **env);
void	processus_2(char *out_file, char *cmd, int pipefd[2], char **env);

#endif