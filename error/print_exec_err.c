/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exec_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:58:47 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/02 13:17:42 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_cd_err(char *ins, char *arg, char *err_msg)
{
	printf("%s: %s: %s\n", ins, err_msg, arg);
	return (1);
}

int	print_export_err(char *ins, char *arg, int err_flag)
{
	if (err_flag == 1)
	{
		printf("%s: not an identifier: %s\n", ins, arg);
		return (1);
	}
	return (0);
}
