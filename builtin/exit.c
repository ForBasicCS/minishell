/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:53:16 by minchoi           #+#    #+#             */
/*   Updated: 2021/09/30 17:22:10 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_exit(int exit_flag)
{
	printf("Minishell will be over");
	if (exit_flag % 256 != 0)
		printf(": %d", exit_flag % 256);
	printf("\n");
	exit(exit_flag);
}

void	ft_exit(t_cmd *cmd)
{
	int	n;

	n = 0;
	if (cmd->word[2] != NULL)
		printf("%s: too many arguments\n", cmd->word[0]);
	else if (cmd->word[1] != NULL)
	{
		if (ft_atoi(cmd->word[1], &n) == -1)
			print_exit(0);
		print_exit(n);
	}
	print_exit(0);
}
