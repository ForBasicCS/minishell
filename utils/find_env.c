/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:46:47 by minchoi           #+#    #+#             */
/*   Updated: 2021/09/27 13:52:31 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env(char *env_var, char **environ)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (environ[i])
	{
		if (ft_strncmp(env_var, environ[i], ft_strlen(env_var)) == 0
			&& environ[i][ft_strlen(env_var)] == '=')
			tmp = environ[i] + ft_strlen(env_var) + 1;
		i++;
	}
	return (tmp);
}
