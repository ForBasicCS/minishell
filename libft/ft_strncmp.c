/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:39:35 by hynam             #+#    #+#             */
/*   Updated: 2021/09/27 16:40:46 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n && *s1 && *s2)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			break ;
		s1++;
		s2++;
		n--;
	}
	if (n != 0)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	return (0);
}
