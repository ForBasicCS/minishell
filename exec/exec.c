/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:40:48 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/07 13:08:09 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		// 외장형 함수 실행
		return (0);
}
