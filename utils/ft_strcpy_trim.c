/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_trim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:17:29 by hynam             #+#    #+#             */
/*   Updated: 2021/10/26 19:49:59 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_strcpy_trim(char *dest, char trim)
{
	char	*tmp;
	int		i;

	tmp = ft_strdup(dest);
	i = 0;
	while (tmp[i] != 0)
	{
		if (tmp[i] != trim)
		{
			*dest = tmp[i];
			dest++;
		}
		i++;
	}
	*dest = 0;
	free(tmp);
}
