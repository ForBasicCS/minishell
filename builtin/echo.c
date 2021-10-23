/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:25:51 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/23 13:01:24 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_status(char *env_var)
{
	printf("%d", g_status);
	if (env_var[2] != 0)
		printf("%s", &(env_var[2]));
}

int	check_option_n(char **ins, int *n_flag)
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
		*n_flag = 1;
		return (1);
	}
	return (0);
}

void	echo_env(char *env_var, t_list *environ)
{
	char	*env_word;
	int		dollar_sign;
	int		i;

	dollar_sign = ft_strchr(env_var, '$') - env_var;
	if (dollar_sign > 0)
	{
		i = 0;
		while (i < dollar_sign)
			printf("%c", env_var[i++]);
	}
	if (env_var[dollar_sign + 1] == '?')
		echo_status(env_var);
	env_word = find_env_value(&(env_var[dollar_sign + 1]), environ);
	if (env_word != NULL)
		printf("%s", env_word);
}

int	ft_echo(t_cmd *cmd)
{
	int	n_flag;
	int	i;

	i = 1;
	n_flag = 0;
	if (cmd->cmd_num == 0)
		return (0);
	if (cmd->cmd_num > 1)
		if (check_option_n(cmd->word, &n_flag))
			i++;
	while (cmd->word[i])
	{
		if (ft_strchr(cmd->word[i], '$')
			&& *(ft_strchr(cmd->word[i], '$') + 1) != 0)
			echo_env(cmd->word[i], cmd->environ);
		else
			printf("%s", cmd->word[i]);
		i++;
		if (cmd->word[i])
			printf(" ");
	}
	if (n_flag != 1)
		printf("\n");
	g_status = 0;
	return (0);
}
