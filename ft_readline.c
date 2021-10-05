/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:57:37 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/05 14:37:11 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_prompt(void)
{
	char	*tmp;

	tmp = getcwd(NULL, 1024);
	ft_putstr_fd(tmp, 1);
	ft_putstr_fd("> ", 1);
	free(tmp);
}

char	*ft_readline(t_cmd *cmd)
{
	char	*str;

	str = NULL;
	print_prompt();
	set_input_mode(cmd);
	while (read(0, &(cmd->ch), sizeof(int)) > 0)
	{
		if (cmd->ch == 4)
		{
			if (cmd->idx == -1)
				free_ctrl_d(cmd);
			else
				continue ;
		}
		else if (cmd->ch == 127)
			str = put_bs(&(cmd->idx), str);
		else if (cmd->ch == 10)
			break ;
		else
			str = put_else(&(cmd->idx), str, cmd->ch);
		cmd->ch = 0;
	}
	write(0, "\n", 1);
	reset_input_mode(cmd);
	if (!str)
		str = ft_strdup("");
	return (str);
}
