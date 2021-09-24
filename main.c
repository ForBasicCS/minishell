/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:41:40 by hynam             #+#    #+#             */
/*   Updated: 2021/09/24 16:19:26 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	int		status;
	pid_t	pid;
	char	*str;

	str = NULL;
	status = 0;
	while (1)
	{
		str = readline("> ");
		if (ft_strncmp(str, "exit", 4) == 0)
			break;
		pid = fork();
		if (pid == 0)
		{
			if (ft_strncmp(str, "pwd") == 0)
				printf("%s\n", getcwd(NULL, 100));
			exit(3);
		}
		waitpid(pid, &status, 0);
		add_history(str);
		free(str);
	}
	printf("%d\n", status);
	return (0);
}