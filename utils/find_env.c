/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:46:47 by minchoi           #+#    #+#             */
/*   Updated: 2021/09/30 14:50:09 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env(char *env_var, t_list *env)
{
	char	*tmp;

	tmp = NULL;
	while (env)
	{
		if (ft_strncmp(env_var, (char *)env->content, ft_strlen(env_var)) == 0
			&& ((char *)env->content)[ft_strlen(env_var)] == '=')
		{
			tmp = (char *)env->content + ft_strlen(env_var) + 1;
			return (tmp);
		}
		else
			env = env->next;
	}
	return (tmp);
}

char	*make_path(char *path_a, char *path_b)
{
	char	*new_path;

	if (path_a == NULL && path_b == NULL)
		return (NULL);
	new_path = (char *)malloc(ft_strlen(path_a) + ft_strlen(path_b) + 1);
	ft_strlcpy(new_path, path_a, ft_strlen(path_a) + 1);
	ft_strlcpy(new_path + ft_strlen(path_a), path_b, ft_strlen(path_b) + 1);
	return (new_path);
}
