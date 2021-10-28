/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:40:48 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/28 12:56:21 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_bin_child(char *path, t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(path, cmd->word, NULL);
	waitpid(pid, &g_status, 0);
	if (WIFSIGNALED(g_status))
		g_status = 128 + WTERMSIG(g_status);
	else
		g_status = WEXITSTATUS(g_status);
	return (0);
}

int	ft_bin(t_cmd *cmd)
{
	int			i;
	char		*tmp;
	char		*new_path;
	struct stat	s;

	i = -1;
	if (stat(cmd->word[0], &s) == 0)
		return (ft_bin_child(cmd->word[0], cmd));
	tmp = ft_strjoin("/", cmd->word[0]);
	while (cmd->path[++i])
	{
		new_path = ft_strjoin(cmd->path[i], tmp);
		if (stat(new_path, &s) == 0)
		{
			ft_bin_child(new_path, cmd);
			free(tmp);
			free(new_path);
			return (0);
		}
		free(new_path);
	}
	free(tmp);
	return (1);
}

int	exec_builtin(t_cmd *cmd)
{
	char	*cmd_var;

	cmd_var = cmd->word[0];
	if (ft_strcmp(cmd_var, "echo") == 0)
		return (ft_echo(cmd));
	else if (ft_strcmp(cmd_var, "cd") == 0)
		return (ft_cd(cmd));
	else if (ft_strcmp(cmd_var, "pwd") == 0)
		return (ft_pwd(cmd));
	else if (ft_strcmp(cmd_var, "env") == 0)
		return (ft_env(cmd));
	else if (ft_strcmp(cmd_var, "exit") == 0)
		return (ft_exit(cmd));
	else if (ft_strcmp(cmd_var, "export") == 0)
		return (ft_export(cmd));
	else if (ft_strcmp(cmd_var, "unset") == 0)
		return (ft_unset(cmd));
	else
		return (ft_bin(cmd));
}

int	exec_cmd(t_cmd **cmd)
{
	int	ret;

	ret = 0;
	while (*cmd)
	{
		if ((*cmd)->word[0] == NULL)
			return (ret);
		if ((*cmd)->next == NULL && (*cmd)->prev == NULL)
		{
			if (!check_builtin(*cmd))
				ret = exec_builtin(*cmd);
			else
				print_exec_err((*cmd)->word[0], NULL, 5);
		}
		else
			ret = exec_pipe(cmd);
		if ((*cmd)->next == NULL)
			break ;
		*cmd = (*cmd)->next;
	}
	return (ret);
}
