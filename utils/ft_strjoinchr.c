/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:05:38 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/05 12:05:55 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoinchr(char *src, int ch)
{
	size_t	i;
	char	*join;

	i = 0;
	join = (char *)malloc(ft_strlen(src) + 2);
	if (join == 0)
		return (0);
	while (*src)
		join[i++] = *src++;
	join[i++] = ch;
	join[i] = 0;
	return (join);
}
