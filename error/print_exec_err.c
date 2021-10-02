/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exec_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:58:47 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/02 16:26:58 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_exec_err(char *ins, char *arg, int err_flag)
{
	if (err_flag > 0)
	{
		if (err_flag == 1)
			printf("%s: %s: %s\n", ins, strerror(errno), arg);
		else if (err_flag == 2)
			printf("%s: not an identifier: %s\n", ins, arg);
		else if (err_flag == 3)
			printf("%s: not enough arguments\n", ins);
		else if (err_flag == 4)
			printf("%s: %s: invalid parameter name\n", ins, arg);
		return (1);
	}
	return (0);
}
