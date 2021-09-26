/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exec_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:58:47 by minchoi           #+#    #+#             */
/*   Updated: 2021/09/26 16:32:25 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_exec_err(char *ins, char *arg, char *err_msg)
{
	printf("%s: %s: %s\n", ins, err_msg, arg);
	return (1);
}
