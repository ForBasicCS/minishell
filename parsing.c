/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:45:52 by hynam             #+#    #+#             */
/*   Updated: 2021/10/07 14:03:33 by minchoi          ###   ########.fr       */
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

int	is_pipe(t_cmd **cmd, char *str)
{
	if (strcmp(str, "|") == 0)
		(*cmd)->p_type = PIPE;
	else if (strcmp(str, "<") == 0)
		(*cmd)->p_type = INPUT;
	else if (strcmp(str, "<<") == 0)
		(*cmd)->p_type = DOCUMENT;
	else if (strcmp(str, ">") == 0)
		(*cmd)->p_type = OUTPUT;
	else if (strcmp(str, ">>") == 0)
		(*cmd)->p_type = APPEND;
	else
		(*cmd)->p_type = -1;
	return ((*cmd)->p_type);
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
			if (is_pipe(cmd, split[j]) != -1)
				j++;
			else
			{
				(*cmd)->word[i] = ft_strdup(split[j]);
				i++;
				j++;
			}
		}
		(*cmd)->word[i] = NULL;
		if ((*cmd)->next == NULL)
			break ;
		*cmd = (*cmd)->next;
	}
	go_head_cmd(cmd);
}

//파이프가 있는지 없는지 체크하면서 cmd리스트를 추가할지 말지 결정
void	check_pipe(t_cmd **cmd, char **split)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (split[++i])
	{
		//명령어가 하나 들어올때마다 하나씩 증가
		(*cmd)->cmd_num++;
		if (is_pipe(cmd, split[i]) == 0 && !(*cmd)->quote)
		{
			//파이프같은게 들어오면 일단 하나 제거
			(*cmd)->cmd_num--;
			//명령어 리스트 하나 추가
			add_cmd(cmd);
		}
	}
	//가장 마지막 명령어일테니 처음으로 돌려줌
	go_head_cmd(cmd);
	set_word(cmd, split);
}

int	parsing(t_cmd *cmd, char *str)
{
	int		c;
	char	*tmp;
	char	**split;

	c = 0;
	if (str == NULL)
		return (1);
	split = (char **)ft_calloc(count_w(str, ' ') + 2, sizeof(char *));
	if (is_valid(str) || split == NULL)
		return (1);
	while (*str)
	{
		//띄어쓰기가 나오면 다음문자 확인, 아니라면 그 글자를 시작점으로 잡음
		if (*str != ' ')
		{
			tmp = str;
			str = end_point(cmd, str);
			split[c] = (char *)malloc((str - tmp) + 1);
			//시작점에서 끝점까지 복사
			ft_strcpy_trim(split[c++], tmp, str, cmd->quote);
		}
		else
			str++;
	}
	check_pipe(&cmd, split);
	ft_free(split);
	return (0);
}
