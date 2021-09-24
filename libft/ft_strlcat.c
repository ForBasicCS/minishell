/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:12:31 by hynam             #+#    #+#             */
/*   Updated: 2020/12/23 21:58:34 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	n;
	size_t	dlen;
	char	*tmp;

	tmp = (char *)src;
	dlen = ft_strlen(dst);
	if (size <= dlen)
		return (size + ft_strlen(src));
	n = size - dlen;
	while (*dst)
		dst++;
	while (*tmp)
	{
		if (n != 1)
		{
			*dst++ = *tmp;
			n--;
		}
		tmp++;
	}
	*dst = '\0';
	return (dlen + ft_strlen(src));
}
