/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:41:40 by hynam             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/09/26 16:30:39 by hynam            ###   ########.fr       */
=======
/*   Updated: 2021/09/26 15:11:42 by minchoi          ###   ########.fr       */
>>>>>>> 1176484d4efeedc4f33bb5cd21ef37af9618b4ef
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	int		status;
<<<<<<< HEAD
	//pid_t	pid;
=======
>>>>>>> 1176484d4efeedc4f33bb5cd21ef37af9618b4ef
	char	*str;
	t_list	lst;

<<<<<<< HEAD
	init_list(&lst);
=======
	char	**ins;
	int		i;
	char	*buf;
	size_t	size;
	size = 200;
	buf = NULL;

>>>>>>> 1176484d4efeedc4f33bb5cd21ef37af9618b4ef
	str = NULL;
	status = 0;
	while (1)
	{
		printf("%s ", getcwd(buf, size));
		str = readline("> ");
		ins = ft_split(str, ' '); // Parsing 대용
		if (ft_strncmp(ins[0], "exit", ft_strlen(ins[0])) == 0)
			break;
<<<<<<< HEAD
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
=======
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
		
>>>>>>> 1176484d4efeedc4f33bb5cd21ef37af9618b4ef
		add_history(str);
		free(str);
	}
	return (0);
}
