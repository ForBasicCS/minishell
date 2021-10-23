/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:58:52 by hynam             #+#    #+#             */
/*   Updated: 2021/10/23 13:04:56 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_cmd	*cmd, t_list *l_env)
{
	cmd->p_type = -1;
	cmd->quote = 0;
	cmd->word = NULL;
	cmd->cmd_num = 0;
	cmd->next = NULL;
	cmd->prev = NULL;
	cmd->environ = l_env;
	cmd->path = ft_split(find_env_value("PATH", cmd->environ), ':');
}

t_list	*pre_process(char **envp)
{
	int		i;
	t_list	*new;

	i = 0;
	new = ft_lstnew(ft_strdup(envp[0]));
	while (envp[++i])
		ft_lstadd_back(&new, ft_lstnew(ft_strdup(envp[i])));
	set_signal();
	return (new);
}
