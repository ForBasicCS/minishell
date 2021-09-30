/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:25:01 by minchoi           #+#    #+#             */
/*   Updated: 2021/09/30 15:33:01 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_cmd *cmd)
{
	while (cmd->environ)
	{
		printf("%s\n", (char *)cmd->environ->content);
		cmd->environ = cmd->environ->next;
	}
	g_status = 0;
}
