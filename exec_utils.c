/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:34:08 by minchoi           #+#    #+#             */
/*   Updated: 2021/09/26 15:08:25 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_builtin(char **ins)
{
	char	*cmd;

	cmd = ins[0];
	if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0
		|| ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0)
		return (1);
	return (0);
}
