/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:53:16 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/04 17:39:05 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_exit(int exit_flag)
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
	if (cmd->word[2] != NULL)
		printf("%s: too many arguments\n", cmd->word[0]);
	else if (cmd->word[1] != NULL)
	{
		if (ft_atoi(cmd->word[1], &n) == -1)
			return (print_exit(0));
		return (print_exit(n));
	}
	return (print_exit(0));
}
