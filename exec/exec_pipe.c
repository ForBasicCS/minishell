/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:06:10 by hynam             #+#    #+#             */
/*   Updated: 2021/10/04 21:30:03 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_pipe(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	char	**new_argv;

	argv = NULL;
	new_argv = (char **)malloc(sizeof(char *) * (argc + 1));
	for (int i = 1; i < argc; i++)
		new_argv[i] = argv[i];
	new_argv[argc] = NULL;
	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		close(fd[1]);
		new_argv[0] = "echo";
		execve("echo", new_argv, envp);
		close(fd[0]);
	}
	else
	{
		close(fd[0]);
		new_argv[0] = "ls";
		execve("ls", new_argv, envp);
		close(fd[1]);
		wait(NULL);
	}
	return (0);
}