/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:41:40 by hynam             #+#    #+#             */
/*   Updated: 2021/09/26 11:39:15 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	int		status;
	pid_t	pid;
	char	*str;

	char	**ins;
	int		i;

	str = NULL;
	status = 0;
	while (1)
	{
		str = readline("> ");
		ins = ft_split(str, ' '); // Parsing 대용
		if (ft_strncmp(ins[0], "exit", ft_strlen(ins[0])) == 0)
			break;
		pid = fork();
		if (pid == 0)
		{
			if (ft_strncmp(ins[0], "echo", ft_strlen(ins[0])) == 0)
				ft_echo(ins);
			exit(3);
		}
		
		i = 0; // Parsing 대용 free
		while (ins[i])
		{
			free(ins[i]);
			i++;
		}
		free(ins);
		
		waitpid(pid, &status, 0);
		add_history(str);
		free(str);
	}
	printf("%d\n", status);
	return (1);
}
