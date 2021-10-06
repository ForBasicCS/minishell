/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:27:42 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/06 21:35:56 by hynam            ###   ########.fr       */
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
	int		ret;
	char	*str;
	t_list	lst;
	t_cmd	*cmd;

	argc = 1;
	argv = NULL;
	ret = 0;
	while (!ret)
	{
		cmd = (t_cmd *)malloc(sizeof(t_cmd));
		lst.content = cmd;
		init_envp(cmd, envp);
		save_input_mode(cmd);
		init_data(cmd);
		str = ft_readline(cmd);
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
		free_all(&cmd);
		add_history(str);
		free(str);
	}
	return (0);
}
