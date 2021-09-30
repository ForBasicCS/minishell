/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:43:27 by hynam             #+#    #+#             */
/*   Updated: 2021/09/30 17:03:45 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str, int *n)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+' || (str[i] == '-' && str[i + 1] == '\0'))
		return (-1);
	while (str[i] && ft_isdigit(str[i]))
		nbr = nbr * 10 + (str[i++] - '0');
	if (i == 0 || (str[i] && !ft_isdigit(str[i])))
		return (-1);
	*n = nbr * sign;
	return (i);
}
