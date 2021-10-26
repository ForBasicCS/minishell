/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_trim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:17:29 by hynam             #+#    #+#             */
/*   Updated: 2021/10/16 16:18:08 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_strcpy_trim(char *dest, char *s1, char *s2, char trim)
{
	while (s1 < s2)
	{
		if (*s1 == trim)
			s1++;
		else
		{
			*dest = *s1;
			dest++;
			s1++;
		}
	}
	*dest = 0;
}