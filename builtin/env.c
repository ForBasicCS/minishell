/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:25:01 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/23 12:56:10 by hynam            ###   ########.fr       */
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
