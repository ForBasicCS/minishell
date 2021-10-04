/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:25:01 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/04 17:35:30 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_cmd *cmd)
{
	t_list	*tmp;

	if (cmd->word[1] != NULL)
		printf("%s: too many arguments\n", cmd->word[0]);
	tmp = cmd->environ;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	g_status = 0;
	return (0);
}
