/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:49:54 by minchoi           #+#    #+#             */
/*   Updated: 2021/09/26 16:11:28 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_option_n(char **ins)
{
	int	i;

	if (ft_strncmp(ins[1], "-n", 2) == 0)
	{
		i = 1;
		while (ins[1][i])
		{
			if (ins[1][i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_echo(char **ins)
{
	int	n_flag;
	int	i;

	i = 1;
	n_flag = 0;
	if (check_option_n(ins))
	{
		n_flag = 1;
		i++;
	}
	while (ins[i])
	{
		//if () //환경 변수를 출력하는 부분
		//	; 
		//else
			printf("%s", ins[i]);
		i++;
		if (ins[i])
			printf(" ");
	}
	if (n_flag != 1)
		printf("\n");
}
