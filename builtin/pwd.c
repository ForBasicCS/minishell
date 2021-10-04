/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:58:58 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/04 17:37:56 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_cmd *cmd)
{
	char	*pwd;

	if (cmd->word[1] != NULL)
		printf("%s: too many arguments\n", cmd->word[0]);
	pwd = getcwd(0, 1024);
	printf("%s\n", pwd);
	free(pwd);
	g_status = 0;
	return (0);
}
