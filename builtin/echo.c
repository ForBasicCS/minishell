/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:49:54 by minchoi           #+#    #+#             */
/*   Updated: 2021/09/27 13:40:03 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_status(char *env_var)
{
	printf("%s", ft_itoa(g_status));
	if (env_var[2] != 0)
		printf("%s", &(env_var[2]));
}

int	check_option_n(char **ins)
{
	int	i;

	if (ft_strncmp(ins[1], "-n", 2) == 0)
	{
		i = 1;
		while (ins[1][i])
		{
			if (ins[1][i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	echo_env(char *env_var, char **environ)
{
	char	*env_word;

	if (env_var[0] == '$' && env_var[1] == '?')
		echo_status(env_var);
	env_word = find_env(&(env_var[1]), environ);
	if (env_word != NULL)
		printf("%s", env_word);
}

void	ft_echo(t_cmd *cmd)
{
	int	n_flag;
	int	i;

	i = 1;
	n_flag = 0;
	if (check_option_n(cmd->word))
	{
		n_flag = 1;
		i++;
	}
	while (cmd->word[i])
	{
		if (ft_strchr(cmd->word[i], '$')) //환경 변수를 출력하는 부분
			echo_env(cmd->word[i], cmd->environ); 
		else
			printf("%s", cmd->word[i]);
		i++;
		if (cmd->word[i])
			printf(" ");
	}
	if (n_flag != 1)
		printf("\n");
}
