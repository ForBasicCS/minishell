/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:33:43 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/05 14:34:13 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*put_bs(int *idx, char *str)
{
	char	*tmp;

	tmp = NULL;
	if (*idx >= 0)
	{
		--(*idx);
		write(0, "\b \b", 3);
		tmp = str;
		str = ft_strdown(tmp);
		free(tmp);
	}
	return (str);
}

char	*put_else(int *idx, char *str, int ch)
{
	char	*tmp;

	tmp = NULL;
	++(*idx);
	write(0, &ch, sizeof(int));
	if (str == NULL)
		str = ft_chrdup(ch);
	else
	{
		tmp = str;
		str = ft_strjoinchr(tmp, ch);
		free(tmp);
	}
	return (str);
}
