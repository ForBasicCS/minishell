/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:49:54 by minchoi           #+#    #+#             */
/*   Updated: 2021/09/27 14:21:53 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_status(char *env_var)
{
	printf("%s", ft_itoa(g_status));
	if (env_var[2] != 0) // '$?' 은 특수하게 뒤에 문자열이 바로 연결되도 그 부분을 출력함
		printf("%s", &(env_var[2]));
}

int	check_option_n(char **ins)
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
		return (1);
	}
	return (0);
}

void	echo_env(char *env_var, char **environ)
{
	char	*env_word;
	int		dollar_sign;
	int		i;

	dollar_sign = ft_strchr(env_var, '$') - env_var;
	if (dollar_sign > 0) // '$환경변수' 다른 문자열이 있으면 출력
	{
		i = 0;
		while (i < dollar_sign)
			printf("%c", env_var[i++]);
	}
	if (env_var[dollar_sign + 1] == '?') // $? 인 경우 status 값 출력
		echo_status(env_var);
	env_word = find_env(&(env_var[dollar_sign + 1]), environ); // 환경변수 존재유무 체크
	if (env_word != NULL) // 환경변수를 찾은 경우에만 출력 -> (null) 이 출력되는걸 막음
		printf("%s", env_word);
}

void	ft_echo(t_cmd *cmd)
{
	int	n_flag;
	int	i;

	i = 1;
	n_flag = 0;
	if (check_option_n(cmd->word)) // -n 플래그 옵션 체크
	{
		n_flag = 1;
		i++;
	}
	while (cmd->word[i])
	{
		if (ft_strchr(cmd->word[i], '$')
			&& *(ft_strchr(cmd->word[i], '$') + 1) != 0) // 환경 변수를 출력하는 부분
			echo_env(cmd->word[i], cmd->environ); 
		else // 일반적인 출력
			printf("%s", cmd->word[i]);
		i++;
		if (cmd->word[i])
			printf(" ");
	}
	if (n_flag != 1)
		printf("\n");
}
