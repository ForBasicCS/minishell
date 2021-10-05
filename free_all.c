/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:35:31 by hynam             #+#    #+#             */
/*   Updated: 2021/10/05 13:21:41 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(t_cmd *cmd)
{
	ft_free(cmd->word);
	clear_list(&cmd->environ);
}

void	free_ctrl_d(t_cmd *cmd)
{
	clear_list(&cmd->environ);
	free(cmd);
	exit(0);
}
