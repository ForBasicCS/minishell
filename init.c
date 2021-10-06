/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:58:52 by hynam             #+#    #+#             */
/*   Updated: 2021/10/05 20:34:44 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_cmd	*cmd)
{	
	cmd->p_type = -1;
	cmd->quote = 0;
	cmd->word = NULL;
	cmd->ch = 0;
	cmd->idx = -1;
	cmd->cmd_num = 0;
	cmd->next = NULL;
	cmd->prev = NULL;
}

void	init_envp(t_cmd *cmd, char **envp)
{
	int	i;

	i = 0;
	cmd->environ = ft_lstnew(ft_strdup(envp[0]));
	while (envp[++i])
		ft_lstadd_back(&cmd->environ, ft_lstnew(ft_strdup(envp[i])));
}
