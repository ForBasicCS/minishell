/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:27:42 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/10 11:25:36 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*g_environ;

void	handler(int signo)
{
	if (signo == 2)
	{
		printf("\033[%dC  \n", rl_point + 11);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (signo == 3)
	{
		rl_on_new_line();
		rl_redisplay();
		printf("  \033[2D");
	}
}

int	main(int argc, char *argv[], char **envp)
{
	int		ret;
	char	*str;
	t_cmd	*cmd;

	argc = 1;
	argv = NULL;
	ret = 0;
	init_envp(envp);
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	while (!ret)
	{
		str = readline("Minishell> ");
		if (str == NULL)
		{
			ft_putstr_fd("\033[2D", 1);
			exit(1);
		}
		cmd = (t_cmd *)malloc(sizeof(t_cmd));
		init_data(cmd);
		if (parsing(cmd, str))
			printf("unvalid command\n");
		else
		{
			while (cmd)
			{
				if (check_builtin(cmd))
					ret = exec_builtin(cmd);
				if (cmd->next == NULL)
					break ;
				cmd = cmd->next;
			}
		}
		clear_cmd(&cmd);
		add_history(str);
		free(str);
	}
	clear_list(&g_environ);
	return (0);
}
