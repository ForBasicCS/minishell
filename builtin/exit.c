/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:53:16 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/26 14:39:59 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(t_cmd *cmd)
{
	int	n;

	n = 0;
	if (cmd->cmd_num > 2)
	{
		printf("%s: too many arguments\n", cmd->word[0]);
		g_status = 2;
		return (0);
	}
	else if (cmd->cmd_num == 2)
	{
		if (ft_atoi(cmd->word[1], &n) != -1)
			g_status = n % 256;
		else
			g_status = 255;
	}
	printf("Minishell will be over\n");
	return (1);
}
