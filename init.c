/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:58:52 by hynam             #+#    #+#             */
/*   Updated: 2021/10/04 17:35:54 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_cmd	*cmd)
{	
	cmd->i_redir = 0;
	cmd->o_redir = 0;
	cmd->is_pipe = 0;
	cmd->quote = 0;
	cmd->word = NULL;
}

void	init_envp(t_cmd *cmd, char **envp)
{
	int	i;

	i = 0;
	cmd->environ = ft_lstnew(ft_strdup(envp[0]));
	while (envp[++i])
		ft_lstadd_back(&cmd->environ, ft_lstnew(ft_strdup(envp[i])));
}
