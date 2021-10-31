/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:45:52 by hynam             #+#    #+#             */
/*   Updated: 2021/10/23 13:00:48 by hynam            ###   ########.fr       */
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

char	*set_word(t_cmd **cmd, char *split)
{
	char	*tmp;
	int		dollar;
	char	*new_word;

	tmp = NULL;
	if (ft_strchr(split, '$') && (*cmd)->quote != '\'')
	{
		dollar = ft_strchr(split, '$') - split;
		new_word = find_env_value(split + dollar + 1, (*cmd)->environ);
		if (dollar != 0)
			tmp = front_of_env(split, dollar);
		new_word = make_path(tmp, new_word);
		if (tmp != NULL)
			free(tmp);
	}
	else
		new_word = ft_strdup(split);
	return (new_word);
}

void	align_word(t_cmd **cmd, char **split)
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
			if (!(*cmd)->quote && is_pipe(split[j]) != -1)
				j++;
			else
				(*cmd)->word[i++] = set_word(cmd, split[j++]);
		}
		(*cmd)->word[i] = NULL;
		if ((*cmd)->next == NULL)
			break ;
		*cmd = (*cmd)->next;
	}
}

int	check_pipe(t_cmd **cmd, t_list *l_env, char **split)
{
	int	i;
	int	type;

	if (!(*cmd)->quote && check_syntax(split))
	{
		g_status = 2;
		ft_free(split);
		return (1);
	}
	i = -1;
	while (split[++i])
	{
		(*cmd)->cmd_num++;
		type = is_pipe(split[i]);
		if (type != -1 && !(*cmd)->quote)
		{
			(*cmd)->cmd_num--;
			(*cmd)->p_type = type;
			add_cmd(cmd, l_env);
		}
	}
	go_head_cmd(cmd);
	align_word(cmd, split);
	return (0);
}

int	parsing(t_cmd **cmd, t_list *l_env, char *str)
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
	if (check_pipe(cmd, l_env, split))
		return (1);
	go_head_cmd(cmd);
	ft_free(split);
	return (0);
}
