/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:06:10 by hynam             #+#    #+#             */
/*   Updated: 2021/10/12 14:47:02 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	here_doucument(t_cmd **cmd, int fd, char **envp)
{
	char	*str;

	fd = open(".tmp", O_CREAT | O_TRUNC | O_WRONLY);
	while (1)
	{
		str = readline("heredoc> ");
		if (strcmp(str, (*cmd)->next->word[0]) == 0 && (*cmd)->next->word[1] == NULL)
		{
			free(str);
			break ;
		}
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
	}
	(*cmd)->word = ft_arrjoinstr((*cmd)->word, ".tmp");
	exec_builtin(*cmd, envp);
	unlink(".tmp");
	return (0);
}

int	child_process(t_cmd **cmd, char **envp)
{
	int		fd;
	t_cmd	*head;

	head = *cmd;
	while ((*cmd)->next && (*cmd)->p_type != -1)
	{
		if ((*cmd)->p_type == 1)
			fd = open((*cmd)->next->word[0], O_RDONLY);
		else if ((*cmd)->p_type == 2)
			return (here_doucument(cmd, fd, envp));
		else if ((*cmd)->p_type == 3)
			fd = open((*cmd)->next->word[0], O_RDWR | O_CREAT | S_IROTH, 0644);
		else if ((*cmd)->p_type == 4)
			fd = open((*cmd)->next->word[0],
					O_RDWR | O_CREAT | O_APPEND | S_IROTH, 0644);
		if (fd < 0)
			return (1);
		dup2(fd, 1);
		exec_builtin(head, envp);
		close(fd);
		*cmd = (*cmd)->next;
	}
	return (0);
}

int	inout_redir(t_cmd **cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		if (child_process(cmd, envp))
			return (1);
		exit(1);
	}
	else
	{
		waitpid(pid, &(*cmd)->status, 0);
		while ((*cmd)->next)
		{
			if ((*cmd)->next->prev->p_type == 0
				&& (*cmd)->next->p_type == -1)
				break ;
			*cmd = (*cmd)->next;
		}
	}
	return (0);
}

int	pipe_redir(t_cmd **cmd, char **envp)
{
	pid_t	pid;

	if (pipe((*cmd)->fd) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		if ((*cmd)->p_type != -1)
			dup2((*cmd)->fd[0], 1);
		if (check_builtin(*cmd))
			exec_builtin(*cmd, envp);
		exit(1);
	}
	else
	{
		waitpid(pid, &(*cmd)->status, 0);
		close((*cmd)->fd[0]);
		if ((*cmd)->next == NULL && (*cmd)->p_type == -1)
			close((*cmd)->fd[1]);
	}
	return (0);
}

int	exec_pipe(t_cmd **cmd, char **envp)
{
	//파이프나 리다이렉션 뒤에 아무것도 안들어오면 에러처리
	if ((*cmd)->next->word[0] == NULL)
		return (0);
	if ((*cmd)->p_type == 0)
		return (pipe_redir(cmd, envp));
	else
		return (inout_redir(cmd, envp));
}
