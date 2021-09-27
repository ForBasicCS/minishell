/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:45:52 by hynam             #+#    #+#             */
/*   Updated: 2021/09/26 21:06:48 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_valid(char *str)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\\' || str[i] == ';')
			return (1);
		else if (quote == 0 && str[i] == '\'')
			quote = '\'';
		else if (quote == 0 && str[i] == '\"')
			quote = '\"';
		else if (quote && (str[i] == '\'' || str[i] == '\"'))
			quote = 0;
		i++;
	}
	if (quote)
		return (1);
	return (0);
}

void	check_pipe(t_cmd *cmd, char *str)
{
	if (ft_strncmp(str, "<", 1) == 0)
	{
		cmd->is_pipe++;
		cmd->i_redir = 1;
	}
	else if (ft_strncmp(str, "<<", 2) == 0)
	{
		cmd->is_pipe++;
		cmd->i_redir = 2;
	}
	else if (ft_strncmp(str, ">", 1) == 0)
	{
		cmd->is_pipe++;
		cmd->o_redir = 1;
	}
	else if (ft_strncmp(str, ">>", 1) == 0)
	{
		cmd->is_pipe++;
		cmd->o_redir = 2;
	}
}

int	parsing(t_list *lst, char *str)
{
	int	i;
	t_cmd	*cmd;

	i = 0;
	cmd = lst->content;
	cmd->word = ft_split(str, ' ');
	while (cmd->word[i] != NULL)
	{
		if (is_valid(cmd->word[i]))
		{
			cmd->word[0] = NULL;
			return (1);
		}
		check_pipe(cmd, cmd->word[i]);
		i++;
	}
	return (0);
}

void	print_all(t_cmd *cmd)
{
	printf("quote : %c\n", cmd->quote);
	printf("num pipe : %d\n", cmd->is_pipe);
	printf("i_redir : %d\n", cmd->i_redir);
	printf("o_redir : %d\n", cmd->o_redir);
	int	i = 0;
	while (cmd->word[i] != NULL)
	{
		printf("word : %s\n", cmd->word[i]);
		i++;
	}
}