/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:46:47 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/23 20:07:43 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env_value(char *env_key, t_list *env)
{
	char	*tmp;

	tmp = NULL;
	while (env)
	{
		if (ft_strncmp(env_key, (char *)env->content, ft_strlen(env_key)) == 0
			&& ((char *)env->content)[ft_strlen(env_key)] == '=')
		{
			tmp = (char *)env->content + ft_strlen(env_key) + 1;
			return (tmp);
		}
		else
			env = env->next;
	}
	return (tmp);
}

t_list	*find_env(char *env_key, t_list *env)
{
	t_list	*ret;

	ret = NULL;
	while (env)
	{
		if (ft_strncmp(env_key, (char *)env->content, ft_strlen(env_key)) == 0
			&& ((char *)env->content)[ft_strlen(env_key)] == '=')
		{
			ret = env;
			return (ret);
		}
		else
			env = env->next;
	}
	return (ret);
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

char	*front_of_env(char *path, int dollar_sign)
{
	char	*tmp;

	tmp = (char *)malloc(dollar_sign + 1);
	ft_strlcpy(tmp, path, dollar_sign + 1);
	return (tmp);
}
