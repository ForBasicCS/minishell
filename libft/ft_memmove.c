/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:43:52 by hynam             #+#    #+#             */
/*   Updated: 2020/12/25 15:38:54 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void const *src, size_t size)
{
	int				i;
	unsigned char	*tmp_src;
	unsigned char	*tmp_dest;

	tmp_src = (unsigned char *)src;
	tmp_dest = (unsigned char *)dest;
	if (tmp_src == tmp_dest || size == 0)
		return (dest);
	if (tmp_dest > tmp_src && tmp_dest - tmp_src < (int)size)
	{
		i = (int)size;
		while (--i >= 0)
			tmp_dest[i] = tmp_src[i];
	}
	else if (tmp_src > tmp_dest && tmp_src - tmp_dest < (int)size)
	{
		i = -1;
		while (++i < (int)size)
			tmp_dest[i] = tmp_src[i];
	}
	else
		ft_memcpy(dest, src, size);
	return (dest);
}
