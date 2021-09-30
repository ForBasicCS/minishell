/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:58:52 by hynam             #+#    #+#             */
/*   Updated: 2021/09/29 21:25:11 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_cmd	*cmd, char **envp)
{
	int	i;

	i = 0;
	//환경변수 리스트 생성
	cmd->environ = ft_lstnew((char *)envp[0]);
	while (envp[++i])
		ft_lstadd_back(&cmd->environ, ft_lstnew((char *)envp[i]));
	cmd->i_redir = 0;
	cmd->o_redir = 0;
	cmd->is_pipe = 0;
	cmd->quote = 0;
	cmd->word = NULL;
}
