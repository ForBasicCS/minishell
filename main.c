/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:27:42 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/04 21:31:56 by hynam            ###   ########.fr       */
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

	ret = 0;
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	lst.content = cmd;
	init_envp(cmd, envp);
	while (!ret)
	{
		init_data(cmd);
		str = readline(ft_strjoin(getcwd(0, 1024),"> "));
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
			 	ret = exec_builtin(cmd);
			else
				ret = exec_pipe(argc, argv, envp);
			free_all(cmd);
		}
		add_history(str);
		free(str);
	}
	free(cmd);
	return (0);
}
