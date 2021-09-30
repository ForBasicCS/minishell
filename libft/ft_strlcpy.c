/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:23:37 by hynam             #+#    #+#             */
/*   Updated: 2021/09/30 13:29:17 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t	i;
	size_t	len;

	if (dest == NULL || src == NULL)
		return (0);
	len = ft_strlen(src);
	i = 0;
	if (size == 0 || src == NULL)
		return (len);
	while (*src && i++ < size - 1)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (len);
}
