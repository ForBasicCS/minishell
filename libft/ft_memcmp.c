/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:43:40 by hynam             #+#    #+#             */
/*   Updated: 2020/12/24 16:06:55 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void const *ptr1, void const *ptr2, size_t num)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)ptr1;
	p2 = (unsigned char *)ptr2;
	if (num != 0)
	{
		while (num != 0)
		{
			if (*p1++ != *p2++)
				return (*--p1 - *--p2);
			num--;
		}
	}
	return (0);
}
