/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:27:42 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/05 14:26:14 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status = 1;

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
	int		status;
	char	*str;
	t_list	lst;
	t_cmd	*cmd;

	status = 0;
	argc = 1;
	argv = NULL;
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	lst.content = cmd;
	init_envp(cmd, envp);
	save_input_mode(cmd);
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		init_data(cmd);
		str = ft_readline(cmd);
		if (parsing(cmd, str))
		{
			printf("unvalid command\n");
			free(cmd->word);
		}
		else
		{
			/*
			if (!is_pipe())
			{
				if (check_builtin(cmd))
					exec_builtin(cmd);
				else
					print_error();
			}

			else
				자식 | 부모
				exec_pipe();
			*/
			if (check_builtin(cmd))
			 	exec_builtin(cmd);
			ft_free(cmd->word);
		}
		add_history(str);
		free(str);
	}
	free(cmd);
	return (0);
}
