/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:45:52 by hynam             #+#    #+#             */
/*   Updated: 2021/09/29 21:24:57 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//미리 받아온 문자열에서 따옴표의 개수가 올바르지 않은지 파악
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

//dest에 s1 ~ s2까지 복사 but trim문자는 복사 X
void	ft_strcpy_trim(char *dest, char *s1, char *s2, char trim)
{
	while (s1 < s2)
	{
		if (*s1 == trim)
			s1++;
		else
		{
			*dest = *s1;
			dest++;
			s1++;
		}
	}
	*dest = 0;
}

char	*end_point(t_cmd *cmd, const char *str)
{
	char	quote;
	char	*end;

	end = (char *)str;
	quote = 0;
	//따옴표가 온전하면서 띄어쓰기가 나오면 반복문 종료 & end에 그 부분을 저장
	while (*end && (*end != ' ' || quote))
	{
		if (!quote && (*end == '\'' || *end == '\"'))
		{
			quote = *end;
			cmd->quote = *end;
		}
		else if (quote && quote == *end)
			quote = 0;
		end++;
	}
	return (end);
}

int	parsing(t_cmd *cmd, char *str)
{
	int		c;
	char	*tmp;

	c = 0;
	cmd->word = (char **)ft_calloc(count_w(str, ' ') + 2, sizeof(char *));
	if (!str || cmd->word == NULL)
		return (1);
	if (is_valid(str))
		return (1);
	while (*str)
	{
		//띄어쓰기가 나오면 다음문자 확인, 아니라면 그 글자를 시작점으로 잡음
		if (*str != ' ')
		{
			tmp = str;
			str = end_point(cmd, str);
			cmd->word[c] = (char *)malloc((str - tmp) + 1);
			//시작점에서 끝점까지 복사
			ft_strcpy_trim(cmd->word[c++], tmp, str, 0);
		}
		else
			str++;
	}
	return (0);
}
