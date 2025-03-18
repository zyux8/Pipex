/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:10:54 by ohaker            #+#    #+#             */
/*   Updated: 2025/03/17 21:28:03 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

void	error(char *error_msg);
int		main(int argc, char **argv, char **envp);
int		open_file(char *fd, int flags, int mode);
void	call_child(char **argv, char **envp, int *fd);
void	call_parent(char **argv, char **envp, int *fd);
void	execute(char *cmd, char **envp);
void	clear_tab(char **tab);
char	*find_path(char *cmd, char **envp);

#endif