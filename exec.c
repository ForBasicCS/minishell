/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:40:48 by minchoi           #+#    #+#             */
/*   Updated: 2021/09/26 15:10:29 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtin(char **ins)
{
	char	*cmd;

	cmd = ins[0];
	if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0)
		ft_echo(ins);
	else if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0)
		ft_cd(ins);
}
