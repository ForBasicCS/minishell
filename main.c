/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:27:42 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/06 21:34:32 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status = 1;

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
			// go_head_cmd(&cmd);
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
	// free(cmd);
	return (0);
}
