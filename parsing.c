/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:45:52 by hynam             #+#    #+#             */
/*   Updated: 2021/10/16 16:21:07 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*end_point(t_cmd **cmd, const char *str)
{
	char	quote;
	char	*end;

	end = (char *)str;
	quote = 0;
	while (*end && (*end != ' ' || quote))
	{
		if (!quote && (*end == '\'' || *end == '\"'))
		{
			quote = *end;
			(*cmd)->quote = *end;
		}
		else if (quote && quote == *end)
			quote = 0;
		end++;
	}
	return (end);
}

void	set_word(t_cmd **cmd, char **split)
{
	int	i;
	int	j;

	j = 0;
	while (*cmd)
	{
		i = 0;
		(*cmd)->word = (char **)malloc(sizeof(char *) * ((*cmd)->cmd_num + 1));
		while (i < (*cmd)->cmd_num && split[j])
		{
			if (is_pipe(split[j]) != -1 && !(*cmd)->quote)
				j++;
			else
				(*cmd)->word[i++] = ft_strdup(split[j++]);
		}
		(*cmd)->word[i] = NULL;
		if ((*cmd)->next == NULL)
			break ;
		*cmd = (*cmd)->next;
	}
}

void	check_pipe(t_cmd **cmd, char **split)
{
	int	i;
	int	j;
	int	type;

	i = -1;
	j = 0;
	while (split[++i])
	{
		(*cmd)->cmd_num++;
		type = is_pipe(split[i]);
		if (type != -1 && !(*cmd)->quote)
		{
			(*cmd)->cmd_num--;
			(*cmd)->p_type = type;
			add_cmd(cmd);
		}
	}
	go_head_cmd(cmd);
	set_word(cmd, split);
}

int	parsing(t_cmd **cmd, char *str)
{
	int		c;
	char	*tmp;
	char	**split;

	c = 0;
	split = (char **)ft_calloc(count_w(str, ' ') + 2, sizeof(char *));
	if (is_valid(str) || split == NULL)
		return (1);
	while (*str)
	{
		if (*str != ' ')
		{
			tmp = str;
			str = end_point(cmd, str);
			split[c] = (char *)malloc((str - tmp) + 1);
			ft_strcpy_trim(split[c++], tmp, str, (*cmd)->quote);
		}
		else
			str++;
	}
	check_pipe(cmd, split);
	go_head_cmd(cmd);
	ft_free(split);
	return (0);
}
