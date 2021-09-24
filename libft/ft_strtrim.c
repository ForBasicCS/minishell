/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:56:42 by hynam             #+#    #+#             */
/*   Updated: 2020/12/25 00:21:52 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tmp;
	size_t	left;
	size_t	right;

	if (*s1 == 0)
		return (ft_strdup(""));
	if (*set == 0)
		return (ft_strdup((char *)s1));
	left = 0;
	right = ft_strlen(s1) - 1;
	while (s1[left] && ft_strchr(set, s1[left]))
		left++;
	while (s1[right] && ft_strrchr(set, s1[right]))
	{
		if (right == 0)
			break ;
		right--;
	}
	if (left >= right)
		return (ft_strdup(""));
	tmp = (char *)malloc(right - left + 2);
	if (tmp == 0)
		return (0);
	ft_strlcpy(tmp, s1 + left, right - left + 2);
	return (tmp);
}
