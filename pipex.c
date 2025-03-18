/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:35:44 by ohaker            #+#    #+#             */
/*   Updated: 2025/03/17 21:49:19 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	if (!cmd || cmd[0] == '\0')
		cmd = "true";
	args = ft_split(cmd, ' ');
	path = find_path(args[0], envp);
	if (execve(path, args, envp) == -1)
	{
		clear_tab(args);
		// free(path);
		error("Error, command path not found");
	}
}

void	call_child(char **argv, char **envp, int *fd)
{
	int	input_file;

	input_file = open_file(argv[1], O_RDONLY, 0777);
	dup2(input_file, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

void	call_parent(char **argv, char **envp, int *fd)
{
	int	output_file;

	output_file = open_file(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	dup2(output_file, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error("Error, failed to create pipe!");
		pid = fork();
		if (pid == -1)
			error("Error, failed to fork!");
		if (pid == 0)
			call_child(argv, envp, fd);
		waitpid(pid, NULL, 0);
		call_parent(argv, envp, fd);
	}
	else
	{
		write(STDOUT_FILENO, "Error, wrong number of arguments!\n", 34);
		exit(1);
	}
	return (0);
}
