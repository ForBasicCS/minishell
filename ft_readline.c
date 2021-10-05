/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:57:37 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/05 13:05:10 by minchoi          ###   ########.fr       */
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

char	*put_bs(int *idx, char *str)
{
	char	*tmp;

	tmp = NULL;
	if (*idx >= 0)
	{
		--(*idx);
		write(0, "\b \b", 3);
		tmp = str;
		str = ft_strdown(tmp);
		free(tmp);
	}
	return (str);
}

char	*put_else(int *idx, char *str, int ch)
{
	char	*tmp;

	tmp = NULL;
	++(*idx);
	write(0, &ch, sizeof(int));
	if (str == NULL)
		str = ft_chrdup(ch);
	else
	{
		tmp = str;
		str = ft_strjoinchr(tmp, ch);
		free(tmp);
	}
	return (str);
}

void	free_ctrl_d(t_cmd *cmd)
{
	clear_list(&cmd->environ);
	free(cmd);
	exit(0);
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
			free_ctrl_d(cmd);
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
