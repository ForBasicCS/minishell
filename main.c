/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:27:42 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/16 14:59:47 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*g_environ;

int	main(int argc, char *argv[], char **envp)
{
	static int	ret;
	char		*str;
	t_cmd		*cmd;

	if (argc > 1 || argv == NULL)
		return (1);
	init_envp(envp);
	set_signal();
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
		if (parsing(&cmd, str))
			printf("unvalid command\n");
		else
		{
			while (cmd)
			{
				if (cmd->next == NULL && cmd->prev == NULL)
				{
					if (check_builtin(cmd))
						ret = exec_builtin(cmd, envp);
				}
				else
					ret = exec_pipe(&cmd, envp);
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
