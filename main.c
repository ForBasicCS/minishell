/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:27:42 by minchoi           #+#    #+#             */
/*   Updated: 2021/09/30 13:53:58 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status = 1;

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
	while (1)
	{
		init_data(cmd, envp);
		str = readline("> ");
		if (parsing(cmd, str))
		{
			printf("unvalid command\n");
			free(cmd->word);
		}
		else
		{
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