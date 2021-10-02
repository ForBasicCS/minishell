/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 15:04:50 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/02 23:14:36 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_param(char *cmd_word)
{
	int	i;

	i = 0;
	if (ft_isdigit(cmd_word[0]) && ft_atoi(cmd_word, &i) != -1)
		return (0);
	else if (ft_isdigit(cmd_word[0]) && ft_atoi(cmd_word, &i) == -1)
		return (1);
	else if (ft_isalpha(cmd_word[0]) || cmd_word[0] == '_')
	{
		i = 1;
		while (cmd_word[i])
		{
			if (!(ft_isalpha(cmd_word[i]) || cmd_word[i] == '_'
					|| ft_isdigit(cmd_word[i])))
				return (1);
			i++;
		}
		return (0);
	}
	else
		return (1);
}

int	unset_env(t_cmd *cmd, int ret, int i)
{
	if (ft_isdigit(cmd->word[i][0]) && ft_atoi(cmd->word[i], &i) != -1)
		return (export_unset_return(ret));
	remove_list(cmd->environ, cmd->word[i]);
	return (export_unset_return(ret));
}

void	ft_unset(t_cmd *cmd)
{
	int	ret;
	int	i;

	ret = 0;
	if (cmd->word[1] == NULL)
		ret = print_exec_err(cmd->word[0], NULL, 3);
	i = 1;
	while (cmd->word[i])
	{
		if (check_param(cmd->word[i]))
			ret = print_exec_err(cmd->word[0], cmd->word[i], 4);
		else
			ret = unset_env(cmd, ret, i);
		i++;
	}
	if (ret == 1)
		g_status = 1;
	else
		g_status = 0;
}
