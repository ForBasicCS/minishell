/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:27:42 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/23 13:26:15 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status;

int	main(int argc, char *argv[], char **envp)
{
	static int	ret;
	char		*str;
	t_cmd		*cmd;
	t_list		*l_env;

	if (argc > 1 || argv == NULL)
		return (1);
	l_env = pre_process(envp);
	while (!ret)
	{
		str = readline("Minishell> ");
		if (str == NULL)
			none_ctrl_d();
		cmd = (t_cmd *)malloc(sizeof(t_cmd));
		init_data(cmd, l_env);
		if (parsing(&cmd, l_env, str))
			printf("Minishell: syntax error\n");
		else
			ret = exec_cmd(&cmd, envp);
		clear_cmd(&cmd, &str);
	}
	clear_list(&l_env);
	return (0);
}
