/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:27:14 by hynam             #+#    #+#             */
/*   Updated: 2020/12/23 21:50:37 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(src);
	tmp = (char *)malloc(len + 1);
	if (tmp == 0)
		return (0);
	ft_strlcpy(tmp, src, len + 1);
	return (tmp);
}
