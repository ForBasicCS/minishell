/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 11:55:04 by minchoi           #+#    #+#             */
/*   Updated: 2021/09/30 14:48:50 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*front_of_env(char *path, int dollar_sign)
{
	char	*tmp;

	tmp = (char *)malloc(dollar_sign + 1);
	ft_strlcpy(tmp, path, dollar_sign + 1);
	return (tmp);
}

int	cd_home(t_cmd *cmd, char *path)
{
	char	*new_path;

	new_path = find_env("HOME", cmd->environ);
	if (ft_strncmp(path, "~", ft_strlen(path)) == 0)
		new_path = make_path(new_path, NULL);
	else
		new_path = make_path(new_path, path + 1);
	if (new_path == NULL)
		return (0);
	if (chdir(new_path) == -1)
		return (print_exec_err(cmd->word[0], path + 1, strerror(errno)));
	return (0);
}

int	cd_env(t_cmd *cmd, char *path)
{
	char	*new_path;
	char	*tmp;
	int		dollar_sign;

	tmp = NULL;
	dollar_sign = ft_strchr(path, '$') - path;
	new_path = find_env(path + dollar_sign + 1, cmd->environ);
	if (dollar_sign != 0)
		tmp = front_of_env(path, dollar_sign);
	new_path = make_path(tmp, new_path);
	if (tmp != NULL)
		free(tmp);
	if (ft_strlen(new_path) == 0)
	{
		chdir(find_env("HOME", cmd->environ));
		free(new_path);
		return (0);
	}
	if (chdir(new_path) == -1)
	{
		print_exec_err(cmd->word[0], new_path, strerror(errno));
		free(new_path);
		return (1);
	}
	return (0);
}

void	ft_cd(t_cmd *cmd)
{
	char	*path;
	int		ret;

	ret = 0;
	path = cmd->word[1];
	if (path == NULL || ft_strncmp(path, "~", 1) == 0)
		ret = cd_home(cmd, path);
	else if (ft_strchr(path, '$'))
		ret = cd_env(cmd, path);
	else
	{
		if (chdir(path) == -1)
			ret = print_exec_err(cmd->word[0], path, strerror(errno));
	}
	if (ret == 1)
		g_status = 1;
	else
		g_status = 0;
}
