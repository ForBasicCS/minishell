/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:46:11 by hynam             #+#    #+#             */
/*   Updated: 2021/10/23 23:20:46 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	go_head_cmd(t_cmd **cmd)
{
	while (*cmd && (*cmd)->prev)
		*cmd = (*cmd)->prev;
}

void	clear_cmd(t_cmd **cmd, char **str)
{
	int		i;
	t_cmd	*tmp;

	while (*cmd)
	{
		i = -1;
		tmp = (*cmd)->prev;
		if ((*cmd)->word != NULL)
		{
			while (++i < (*cmd)->cmd_num + 1)
				free((*cmd)->word[i]);
			free((*cmd)->word);
		}
		i = -1;
		while ((*cmd)->path[++i] != NULL)
			free((*cmd)->path[i]);
		free((*cmd)->path);
		free(*cmd);
		*cmd = NULL;
		*cmd = tmp;
	}
	add_history(*str);
	free(*str);
}

//원래의 cmd에 새로운 cmd를 추가하고, 새로운 cmd를 가리키도록 수정
void	add_cmd(t_cmd **cmd, t_list *l_env)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	init_data(new, l_env);
	if (*cmd)
	{
		(*cmd)->next = new;
		new->prev = *cmd;
	}
	*cmd = new;
}

void	remove_cmd(t_cmd **cmd)
{
	t_cmd	*tmp;

	if (*cmd)
	{
		tmp = (*cmd)->next;
		free(*cmd);
		*cmd = tmp;
	}
}
