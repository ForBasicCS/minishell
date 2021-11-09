/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:06:10 by hynam             #+#    #+#             */
/*   Updated: 2021/10/28 13:26:45 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redir_process(t_cmd **cmd)
{
	int		fd;
	int		flag;
	t_cmd	*head;

	head = *cmd;
	flag = 0;
	if ((*cmd)->p_type == 2)
		here_document(cmd, set_redir_fd(cmd));
	while ((*cmd)->next && (*cmd)->p_type != 0)
	{
		flag = set_flag(cmd, &fd);
		*cmd = (*cmd)->next;
	}
	if (!check_builtin(head))
		exec_builtin(head);
	if (flag == -1)
		print_exec_err((*cmd)->word[0], NULL, 6);
	unlink(".tmp");
	return (g_status);
}

void	child_process(t_cmd **cmd, int *fd, int n, int *i)
{
	(*cmd)->pid = fork();
	if ((*cmd)->pid == 0)
	{
		set_pipe_fd(cmd, fd, n, i);
		if ((*cmd)->p_type > 0)
			g_status = redir_process(cmd);
		else
			exec_builtin(*cmd);
		exit(g_status);
	}
}

void	wait_process(t_cmd *cmd, int *fd, int n)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->pid != -1)
		{
			waitpid(tmp->pid, &g_status, 0);
			g_status = WEXITSTATUS(g_status);
		}
		else
			g_status = 127;
		while (tmp->p_type > 0)
			tmp = tmp->next;
		close_all(fd, n);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
}

int	pipe_redir(t_cmd **cmd, int *fd, int n)
{
	int		i;

	i = 0;
	while (*cmd)
	{
		if (!check_builtin(*cmd))
			child_process(cmd, fd, n, &i);
		else
			print_exec_err((*cmd)->word[0], NULL, 6);
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

int	exec_pipe(t_cmd **cmd)
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
	pipe_redir(cmd, fd, n);
	wait_process(tmp, fd, n);
	if (n)
		free(fd);
	return (0);
}
