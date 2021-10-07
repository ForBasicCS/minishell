/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:53:16 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/07 13:10:00 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_exit(int exit_flag)
{
	printf("Minishell will be over");
	if (exit_flag % 256 != 0)
		printf(": %d", exit_flag % 256);
	printf("\n");
	return (1);
}

int	ft_exit(t_cmd *cmd)
{
	int	n;

	n = 0;
	if (cmd->cmd_num != 1)
		printf("%s: too many arguments\n", cmd->word[0]);
	else if (cmd->cmd_num == 2)
	{
		if (ft_atoi(cmd->word[1], &n) == -1)
			return (print_exit(0));
		return (print_exit(n));
	}
	return (print_exit(0));
}
