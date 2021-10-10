/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:46:11 by hynam             #+#    #+#             */
/*   Updated: 2021/10/09 16:14:11 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	go_head_cmd(t_cmd **cmd)
{
	while (*cmd && (*cmd)->prev)
		*cmd = (*cmd)->prev;
}

void	clear_cmd(t_cmd **cmd)
{
	int		i;
	t_cmd	*tmp;

	go_head_cmd(cmd);
	while ((*cmd)->next)
	{
		i = -1;
		tmp = (*cmd)->next;
		while (++i < (*cmd)->cmd_num + 1)
			free((*cmd)->word[i]);
		free((*cmd)->word);
		free(*cmd);
		*cmd = tmp;
	}
	free(*cmd);
}

//원래의 cmd에 새로운 cmd를 추가하고, 새로운 cmd를 가리키도록 수정
void	add_cmd(t_cmd **cmd)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	init_data(new);
	if (*cmd)
	{
		(*cmd)->next = new;
		new->prev = *cmd;
	}
	*cmd = new;
}
