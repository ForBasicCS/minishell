/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:41:40 by hynam             #+#    #+#             */
/*   Updated: 2021/09/26 16:39:53 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char **envp)
{
	int		status;
	char	*str;

	char	**ins;
	int		i;
	char	*buf;
	buf = NULL;
	argc = 0;
	argv = NULL;
	while (envp[argc])
	{
		printf("%s\n", envp[argc]);
		argc++;
	}

	str = NULL;
	status = 0;
	while (1)
	{
		printf("%s ", getcwd(buf, 1024));
		str = readline("> ");
		ins = ft_split(str, ' '); // Parsing 대용
		if (ft_strncmp(ins[0], "exit", ft_strlen(ins[0])) == 0)
			break;
		if (check_builtin(ins))
			exec_builtin(ins);
		else
			printf("It is not built-in func\n");
		
		i = 0; // Parsing 대용 free
		while (ins[i])
		{
			free(ins[i]);
			i++;
		}
		free(ins);
		
		add_history(str);
		free(str);
	}
	return (0);
}
