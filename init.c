/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:58:52 by hynam             #+#    #+#             */
/*   Updated: 2021/09/26 16:32:23 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_cmd	*cmd)
{
	cmd->environ = NULL;
	cmd->i_redir = 0;
	cmd->o_redir = 0;
	cmd->is_pipe = 0;
	cmd->quote = 0;
	cmd->word = NULL;
}

void	init_list(t_list *lst)
{
	init_data(lst->content);
	lst->next = NULL;
}

t_list	*new_list(t_list *lst, t_cmd *cmd)
{
	t_list *new_lst;

	new_lst = (t_list *)malloc(sizeof(t_list));
	lst->next = new_lst;
	new_lst->content = cmd;
	new_lst->next = NULL;
	return (new_lst);
}

void	remove_list(t_list *lst)
{
	t_list	*tmp;

	tmp = lst->next;
	while (tmp != NULL)
	{
		free(tmp);
		tmp = tmp->next;
	}
}