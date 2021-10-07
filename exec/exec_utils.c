/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:34:08 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/07 12:59:24 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_builtin(t_cmd *cmd)
{
	char	*cmd_var;

	cmd_var = cmd->word[0];
	// ft_strcmp 만들면 그거로 변경
	if (ft_strcmp(cmd_var, "echo") == 0
		|| ft_strcmp(cmd_var, "cd") == 0
		|| ft_strcmp(cmd_var, "pwd") == 0
		|| ft_strcmp(cmd_var, "env") == 0
		|| ft_strcmp(cmd_var, "exit") == 0
		|| ft_strcmp(cmd_var, "export") == 0
		|| ft_strcmp(cmd_var, "unset") == 0)
		return (1);
	/*
	else if (절대 상대 경로 함수)
	{
		
	}
	*/
	return (0);
}
