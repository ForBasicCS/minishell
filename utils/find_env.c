/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:46:47 by minchoi           #+#    #+#             */
/*   Updated: 2021/09/30 13:58:37 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env(char *env_var, t_list *environ)
{
	char	*tmp;

	tmp = NULL;
	while (environ)
	{
		if (ft_strncmp(env_var, (char *)environ->content, ft_strlen(env_var)) == 0
			&& ((char *)environ->content)[ft_strlen(env_var)] == '=')
		{
			tmp = (char *)environ->content + ft_strlen(env_var) + 1;
			return (tmp);
		}
		else
			environ = environ->next;
	}
	return (tmp);
}
