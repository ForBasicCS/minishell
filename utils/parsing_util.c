/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:16:53 by hynam             #+#    #+#             */
/*   Updated: 2021/10/16 16:18:45 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid(char *str)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\\' || str[i] == ';')
			return (1);
		if (quote == 0 && (str[i] == '\"' || str[i] == '\''))
			quote = str[i];
		else if (quote && str[i] == quote)
			quote = 0;
		i++;
	}
	if (quote)
		return (1);
	return (0);
}

int	is_pipe(char *str)
{
	if (ft_strcmp(str, "|") == 0)
		return (PIPE);
	else if (ft_strcmp(str, "<") == 0)
		return (INPUT);
	else if (ft_strcmp(str, "<<") == 0)
		return (DOCUMENT);
	else if (ft_strcmp(str, ">") == 0)
		return (OUTPUT);
	else if (ft_strcmp(str, ">>") == 0)
		return (APPEND);
	return (-1);
}

int	check_syntax(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		if (is_pipe(split[i]) == 0
			&& (i == 0 || split[i + 1] == NULL || is_pipe(split[i + 1]) != -1))
			return (1);
		else if (is_pipe(split[i]) > 0
			&& (split[i + 1] == NULL || is_pipe(split[i + 1]) != -1))
			return (1);
	}
	return (0);
}
