/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exec_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:58:47 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/28 13:19:14 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_exec_err(char *ins, char *arg, int err_flag)
{
	if (err_flag > 0)
	{
		if (err_flag == 1)
			printf("%s: %s: %s\n", ins, arg, strerror(errno));
		else if (err_flag == 2)
			printf("%s: not an identifier: %s\n", ins, arg);
		else if (err_flag == 3)
			printf("%s: not enough arguments\n", ins);
		else if (err_flag == 4)
			printf("%s: %s: invalid parameter name\n", ins, arg);
		else if (err_flag == 5)
			printf("%s: HOME not set\n", ins);
		else
		{
			printf("command not found: %s\n", ins);
			g_status = 127;
		}
		return (1);
	}
	return (0);
}
