/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 11:55:04 by minchoi           #+#    #+#             */
/*   Updated: 2021/09/26 16:40:33 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_home(char **ins, char *path)
{
	ins = NULL;
	path = NULL;
	return (0);
}

void	ft_cd(char **ins)
{
	char	*path;
	int		ret;

	path = ins[1];
	if (ins[1] == NULL || ft_strncmp(path, "~", ft_strlen(path)) == 0)
		ret = cd_home(ins, path);
	//else if (ins[1][0] == '$') //경로가 환경변수 일 때
	else
	{
		path = ins[1];
		if (chdir(path) == -1)
			ret = print_exec_err(ins[0], path, strerror(errno)); //에러 출력
	}
	/*
	if (ret == 1) //cd 명령어가 정상적으로 수행되지 않았을 떄
		status = 1
	else
		status = 0
	*/
}
