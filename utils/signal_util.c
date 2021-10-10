/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:19:14 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/10 14:27:55 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler_int(pid_t pid)
{
	if (pid == -1)
	{
		printf("\033[%dC  \n", rl_point + 11);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else
		printf("\n");
}

void	handler(int signo)
{
	pid_t	pid;
	int		status;

	pid = waitpid(-1, &status, WNOHANG);
	if (signo == 2)
		handler_int(pid);
	else if (signo == 3)
	{
		if (pid == -1)
		{
			rl_on_new_line();
			rl_redisplay();
			printf("  \033[2D");
		}
		else
			printf("minishell: quit\n");
	}
}

void	set_signal(void)
{
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
}
