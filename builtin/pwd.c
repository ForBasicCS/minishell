/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:58:58 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/23 12:56:35 by hynam            ###   ########.fr       */
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
