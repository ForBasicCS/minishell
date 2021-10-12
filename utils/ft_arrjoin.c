/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:47:43 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/12 14:41:58 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_arrlen(char **src)
{
	int	i;

	i = 0;
	while (src[i] != NULL)
		i++;
	return (i);
}

char	**ft_arrjoinstr(char **s1, char *s2)
{
	int		arrlen;
	int		i;
	int		j;
	char	**tmp;

	arrlen = ft_arrlen(s1);
	tmp = (char **)malloc(sizeof(char *) * (arrlen + 2));
	i = 0;
	while (s1[i] != NULL)
	{
		tmp[i] = s1[i];
		i++;
	}
	free(s1);
	tmp[i] = (char *)malloc(sizeof(char) * (ft_strlen(s2) + 1));
	j = -1;
	while (s2[++j] != '\0')
		tmp[i][j] = s2[j];
	tmp[i++][j] = '\0';
	tmp[i] = NULL;
	return (tmp);
}
