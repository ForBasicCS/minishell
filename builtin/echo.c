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

int	ft_echo(t_cmd *cmd)
{
	int	n_flag;
	int	i;

	i = 1;
	n_flag = 0;
	if (cmd->word[1] != NULL)
		if (check_option_n(cmd->word, &n_flag))
			i++;
	while (cmd->word[i])
	{
		printf("%s", cmd->word[i++]);
		if (cmd->word[i])
			printf(" ");
	}
	if (n_flag != 1)
		printf("\n");
	g_status = 0;
	return (0);
}
