/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:35:31 by hynam             #+#    #+#             */
/*   Updated: 2021/10/06 21:35:31 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(t_cmd **cmd)
{
	clear_cmd(cmd);
	// clear_list(&(*cmd)->environ);
}

void	free_ctrl_d(t_cmd *cmd)
{
	clear_list(&cmd->environ);
	free(cmd);
	exit(0);
}
