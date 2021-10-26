/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 11:55:04 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/23 12:55:42 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cd_home(t_cmd *cmd, char *path)
{
	char	*new_path;

	new_path = find_env_value("HOME", cmd->environ);
	if (ft_strncmp(path, "~", ft_strlen(path)) == 0)
		new_path = make_path(new_path, NULL);
	else
		new_path = make_path(new_path, path + 1);
	if (new_path == NULL)
		return (0);
	if (chdir(new_path) == -1)
		return (print_exec_err(cmd->word[0], path + 1, 1));
	return (0);
}

int	ft_cd(t_cmd *cmd)
{
	char	*path;
	int		ret;

	ret = 0;
	path = cmd->word[1];
	if (path == NULL || ft_strcmp(path, "~") == 0)
		ret = cd_home(cmd, path);
	else
	{
		if (chdir(path) == -1)
			ret = print_exec_err(cmd->word[0], path, 1);
	}
	if (ret == 1)
		g_status = 1;
	else
		g_status = 0;
	return (0);
}
