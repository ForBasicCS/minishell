/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:44:47 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/05 13:21:07 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_list *environ)
{
	while (environ)
	{
		printf("%s\n", (char *)environ->content);
		environ = environ->next;
	}
}

int	check_key(t_cmd *cmd, int i)
{
	if (ft_isalpha(cmd->word[i][0]) || cmd->word[i][0] == '_')
		return (0);
	else
		return (1);
}

int	new_env(t_cmd *cmd, int i, int ret)
{
	char	*tmp;
	char	*key;
	t_list	*new;

	tmp = ft_strchr(cmd->word[i], '=');
	if (tmp == NULL)
		return (export_unset_return(ret));
	key = front_of_env(cmd->word[i], (tmp - cmd->word[i]));
	new = find_env(key, cmd->environ);
	free(key);
	tmp = ft_strdup(cmd->word[i]);
	if (new != NULL)
	{
		free(new->content);
		new->content = tmp;
	}
	else
		ft_lstadd_back(&cmd->environ, ft_lstnew(ft_strdup(tmp)));
	return (export_unset_return(ret));
}	

int	ft_export(t_cmd *cmd)
{
	int	ret;
	int	i;

	ret = 0;
	if (cmd->word[1] == NULL)
		print_env(cmd->environ);
	i = 0;
	while (cmd->word[++i])
	{
		if (check_key(cmd, i))
		{
			if (ft_strchr(cmd->word[i], '=') != NULL)
				ret = print_exec_err(cmd->word[0], front_of_env(cmd->word[i],
							ft_strchr(cmd->word[i], '=') - cmd->word[i]), 2);
			else
				ret = print_exec_err(cmd->word[0], cmd->word[i], 2);
		}
		else
			ret = new_env(cmd, i, ret);
	}
	if (ret == 1)
		g_status = 1;
	else
		g_status = 0;
	return (0);
}
