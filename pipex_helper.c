/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:51:37 by ohaker            #+#    #+#             */
/*   Updated: 2025/03/12 22:45:19 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *error_msg)
{
	perror(error_msg);
	exit(EXIT_FAILURE);
}

int	open_file(char *fd, int flags, int mode)
{
	int	file;

	file = open(fd, flags, mode);
	if (file == -1)
		error("Error, file open failed");
	return (file);
}

void	clear_tab(char **tab)
{
	size_t	x;

	x = 0;
	while (tab[x])
	{
		free(tab[x]);
		x++;
	}
	free(tab);
}

char	*find_path(char *cmd, char **envp)
{
	int		x;
	char	**allpaths;
	char	*whole_path;
	char	*path;

	x = 0;
	while (envp[x] && ft_strncmp(envp[x], "PATH=", 5) != 0)
		x++;
	allpaths = ft_split(envp[x] + 5, ':');
	x = -1;
	while (allpaths[++x])
	{
		path = ft_strjoin(allpaths[x], "/");
		whole_path = ft_strjoin(path, cmd);
		free(path);
		if (access(whole_path, F_OK) == 0)
		{
			clear_tab(allpaths);
			return (whole_path);
		}
		free(whole_path);
	}
	clear_tab(allpaths);
	return (NULL);
}
