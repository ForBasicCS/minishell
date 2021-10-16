/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:27:42 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/16 16:48:41 by minchoi          ###   ########.fr       */
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
	pre_process(envp);
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
			ret = exec_cmd(&cmd, envp);
		clear_cmd(&cmd, str);
	}
	clear_list(&g_environ);
	return (0);
}
