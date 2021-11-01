/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 11:55:04 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/26 13:12:51 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	update_pwd(t_cmd *cmd, char *path)
{
	t_list	*tmp;
	char	*key;
	char	*new_path;

	tmp = find_env(path, cmd->environ);
	key = make_path(path, "=");
	path = getcwd(0, 1024);
	new_path = make_path(key, path);
	free(key);
	free(path);
	free(tmp->content);
	tmp->content = new_path;
	return (0);
}

static int	cd_home(t_cmd *cmd, char *path)
{
	char		*new_path;
	struct stat	s;

	new_path = find_env_value("HOME", cmd->environ);
	if (stat(new_path, &s) == 0 && find_env("OLDPWD", cmd->environ) != NULL)
		update_pwd(cmd, "OLDPWD");
	if (chdir(new_path) == -1)
		return (print_exec_err(cmd->word[0], path, 5));
	return (0);
}

int	ft_cd(t_cmd *cmd)
{
	char		*path;
	int			ret;
	struct stat	s;

	ret = 0;
	path = cmd->word[1];
	if (path == NULL || ft_strcmp(path, "~") == 0)
		ret = cd_home(cmd, path);
	else
	{
		if (stat(path, &s) == 0 && find_env("OLDPWD", cmd->environ) != NULL)
			update_pwd(cmd, "OLDPWD");
		if (chdir(path) == -1)
			ret = print_exec_err(cmd->word[0], path, 1);
	}
	if (ret == 1)
		g_status = 1;
	else
	{
		if (find_env("PWD", cmd->environ) != NULL)
			update_pwd(cmd, "PWD");
		g_status = 0;
	}
	return (0);
}
