/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:41:40 by hynam             #+#    #+#             */
/*   Updated: 2021/09/27 13:28:47 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status = 1;

int	main(int argc, char *argv[], char **envp)
{
	int		status;
	char	*str;

	int		i;
	char	*buf;
	buf = NULL;
	argc = 0;
	argv = NULL;
	t_cmd	*cmd;
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		printf("Error: Failed to allocate.");
	cmd->environ = envp;
	while (cmd->environ[argc])
	{
		printf("%s\n", cmd->environ[argc]);
		argc++;
	}

	str = NULL;
	status = 0;
	while (1)
	{
		printf("%s ", getcwd(buf, 1024));
		str = readline("> ");
		cmd->word = ft_split(str, ' '); // Parsing 대용
		if (ft_strncmp(cmd->word[0], "exit", ft_strlen(cmd->word[0])) == 0)
			break;
		if (check_builtin(cmd))
			exec_builtin(cmd);
		else
			printf("It is not built-in func\n");
		
		i = 0; // Parsing 대용 free
		while (cmd->word[i])
		{
			free(cmd->word[i]);
			i++;
		}
		free(cmd->word);
		
		add_history(str);
		free(str);
	}
	free(cmd);
	return (0);
}
