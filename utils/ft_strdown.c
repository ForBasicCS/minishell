/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdown.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:15:46 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/05 12:24:54 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdown(char *str)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(str);
	tmp = (char *)malloc(ft_strlen(str));
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, str, len);
	return (tmp);
}
