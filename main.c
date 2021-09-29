/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:41:40 by hynam             #+#    #+#             */
/*   Updated: 2021/09/29 21:18:45 by hynam            ###   ########.fr       */
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
			// if (check_builtin(cmd))
			// 	exec_builtin(cmd);
			ft_free(cmd->word);
		}
		add_history(str);
		free(str);
	}
	free(cmd);
	return (0);
}
