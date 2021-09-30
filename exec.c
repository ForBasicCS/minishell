/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:40:48 by minchoi           #+#    #+#             */
/*   Updated: 2021/09/30 16:03:05 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtin(t_cmd *cmd)
{
	char	*cmd_var;

	cmd_var = cmd->word[0];
	if (ft_strncmp(cmd_var, "echo", ft_strlen(cmd_var)) == 0)
		ft_echo(cmd);
	else if (ft_strncmp(cmd_var, "cd", ft_strlen(cmd_var)) == 0)
		ft_cd(cmd);
	else if (ft_strncmp(cmd_var, "pwd", ft_strlen(cmd_var)) == 0)
		ft_pwd();
	else if (ft_strncmp(cmd_var, "env", ft_strlen(cmd_var)) == 0)
		ft_env(cmd);
	else if (ft_strncmp(cmd_var, "exit", ft_strlen(cmd_var)) == 0)
		ft_exit(cmd);
}
