/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:40:48 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/23 12:55:03 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_bin_child(char *path, t_cmd *cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(path, cmd->word, envp);
	waitpid(pid, &g_status, 0);
	return (0);
}

int	ft_bin(t_cmd *cmd, char **envp)
{
	int			i;
	char		*tmp;
	char		*new_path;
	struct stat	s;

	i = -1;
	if (stat(cmd->word[0], &s) == 0)
		return (ft_bin_child(cmd->word[0], cmd, envp));
	tmp = ft_strjoin("/", cmd->word[0]);
	while (cmd->path[++i])
	{
		new_path = ft_strjoin(cmd->path[i], tmp);
		if (stat(new_path, &s) == 0)
		{
			ft_bin_child(new_path, cmd, envp);
			free(tmp);
			free(new_path);
			return (0);
		}
		free(new_path);
	}
	free(tmp);
	return (1);
}

int	exec_builtin(t_cmd *cmd, char **envp)
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
		return (ft_bin(cmd, envp));
}

int	exec_cmd(t_cmd **cmd, char **envp)
{
	int	ret;

	ret = 0;
	while (*cmd)
	{
		if ((*cmd)->next == NULL && (*cmd)->prev == NULL)
		{
			if (check_builtin(*cmd))
				ret = exec_builtin(*cmd, envp);
		}
		else
			ret = exec_pipe(cmd, envp);
		if ((*cmd)->next == NULL)
			break ;
		*cmd = (*cmd)->next;
	}
	return (ret);
}
