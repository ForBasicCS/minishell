/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:27:42 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/07 13:12:36 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*g_environ;

void	handler(int signo)
{
	if (signo == 2)
	{
		write(0, "\n", 1);
		print_prompt();
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
	while (!ret)
	{
		str = readline(ft_strjoin(getcwd(0, 1024), "> "));
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
