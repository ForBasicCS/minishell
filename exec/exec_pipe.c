/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:06:10 by hynam             #+#    #+#             */
/*   Updated: 2021/10/13 16:01:06 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redir_process(t_cmd **cmd, char **envp)
{
	int		i;
	int		fd[250];
	int		flag;
	t_cmd	*head;

	head = *cmd;
	i = 0;
	while ((*cmd)->next && (*cmd)->p_type != 0)
	{
		flag = 0;
		fd[i] = set_redir_fd(cmd);
		if ((*cmd)->p_type == 1)
		{
			flag = 1;
			dup2(fd[i], 0);
		}
		else
			dup2(fd[i], 1);
		if (!flag && check_builtin(head))
			exec_builtin(head, envp);
		*cmd = (*cmd)->next;
	}
	if (flag && check_builtin(head))
		exec_builtin(head, envp);
	return (0);
}

int	pipe_redir(t_cmd **cmd, char **envp, int *fd, int n)
{
	int		i;

	i = 0;
	while (*cmd)
	{
		if (fork() == 0)
		{
			set_pipe_fd(cmd, fd, n, &i);
			if ((*cmd)->p_type > 0)
				redir_process(cmd, envp);
			else
				exec_builtin(*cmd, envp);
			exit(1);
		}
		while ((*cmd)->p_type > 0)
			*cmd = (*cmd)->next;
		if ((*cmd)->p_type == 0)
			++i;
		if ((*cmd)->next == NULL)
			break ;
		*cmd = (*cmd)->next;
	}
	return (0);
}

int	exec_pipe(t_cmd **cmd, char **envp)
{
	int		i;
	int		n;
	int		*fd;
	t_cmd	*tmp;

	i = -1;
	n = create_fd(cmd, &fd);
	while (++i < n / 2)
		pipe(fd + i * 2);
	tmp = *cmd;
	pipe_redir(cmd, envp, fd, n);
	while (tmp)
	{
		wait(&tmp->status);
		close_all(fd, n);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	if (n)
		free(fd);
	return (0);
}
