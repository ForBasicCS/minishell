/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:43:38 by hynam             #+#    #+#             */
/*   Updated: 2020/12/23 15:39:17 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *ptr, int value, size_t num)
{
	size_t	i;

	value = (unsigned char)value;
	i = 0;
	while (i < num)
	{
		if (((unsigned char *)ptr)[i] == value)
			return ((unsigned char *)ptr + i);
		i++;
	}
	return (0);
}
