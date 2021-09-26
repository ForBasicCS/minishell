/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:41:40 by hynam             #+#    #+#             */
/*   Updated: 2021/09/26 16:30:39 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	int		status;
	//pid_t	pid;
	char	*str;
	t_list	lst;

	init_list(&lst);
	str = NULL;
	status = 0;
	while (1)
	{
		str = readline("> ");
		if (ft_strncmp(str, "exit", 4) == 0)
			break;
		if(parsing(&lst, str))
		{
			printf("error!\n");
			return (1);
		}
		// pid = fork();
		// if (pid == 0)
		// {
		// 	if (ft_strncmp(str, "pwd", 3) == 0)
		// 		printf("%s\n", getcwd(NULL, 100));
		// 	exit(3);
		// }
		// waitpid(pid, &status, 0);
		add_history(str);
		free(str);
	}
	printf("%d\n", status);
	return (0);
}