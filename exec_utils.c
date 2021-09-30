/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:34:08 by minchoi           #+#    #+#             */
/*   Updated: 2021/09/30 15:29:34 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_builtin(t_cmd *cmd)
{
	char	*cmd_var;

	cmd_var = cmd->word[0];
	if (ft_strncmp(cmd_var, "echo", ft_strlen(cmd_var)) == 0
		|| ft_strncmp(cmd_var, "cd", ft_strlen(cmd_var)) == 0
		|| ft_strncmp(cmd_var, "pwd", ft_strlen(cmd_var)) == 0
		|| ft_strncmp(cmd_var, "env", ft_strlen(cmd_var)) == 0)
		return (1);
	return (0);
}
