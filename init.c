/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:58:52 by hynam             #+#    #+#             */
/*   Updated: 2021/10/02 14:47:42 by minchoi          ###   ########.fr       */
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

/*
형식아 init_data() 에서 cmd->environ 을 계속 envp 로 초기화하니까 export 로 새롭게 바꾼
환경변수들이 계속 초기화 되서 envp 파트만 따로 빼서 main.c 에서 while 문 밖으로 빼서
1번만 동작하도록 바꿨다.
*/

void	init_envp(t_cmd *cmd, char **envp)
{
	int	i;

	i = 0;
	cmd->environ = ft_lstnew(ft_strdup(envp[0]));
	while (envp[++i])
		ft_lstadd_back(&cmd->environ, ft_lstnew(ft_strdup(envp[i])));
}
