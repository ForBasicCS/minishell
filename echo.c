/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:49:54 by minchoi           #+#    #+#             */
/*   Updated: 2021/09/26 11:49:08 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_echo(char **ins, int flag)
{
	int	i;

	if (flag == 1)
	{
		i = 2;
		while (ins[i])
		{
			printf("%s", ins[i]);
			i++;
			if (ins[i])
				printf(" ");
		}
	}
	else
	{
		i = 1;
		while (ins[i])
		{
			printf("%s", ins[i]);
			i++;
			if (ins[i])
				printf(" ");
		}
		printf("\n");
	}
}

void	ft_echo(char **ins)
{
	if (ft_strncmp(ins[1], "-n", ft_strlen(ins[1])) == 0)
		print_echo(ins, 1);
	else
		print_echo(ins, 0);
}
