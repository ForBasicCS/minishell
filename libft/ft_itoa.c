/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hynam <hynam@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:46:57 by hynam             #+#    #+#             */
/*   Updated: 2020/12/23 21:26:36 by hynam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit(long long n)
{
	int	d;

	if (n < 0)
	{
		n *= -1;
		d = 2;
	}
	else
		d = 1;
	while (n / 10)
	{
		n /= 10;
		d++;
	}
	return (d);
}

char	*ft_itoa(int n)
{
	int			i;
	long long	tmp;
	char		*num;

	tmp = (long long)n;
	num = (char *)malloc(ft_digit(tmp) + 1);
	if (num == NULL)
		return (0);
	i = ft_digit(tmp);
	if (tmp < 0)
	{
		num[0] = '-';
		tmp *= -1;
	}
	num[i--] = '\0';
	if (tmp == 0)
		num[i] = '0';
	while (i >= 0 && tmp)
	{
		num[i] = tmp % 10 + 48;
		tmp /= 10;
		i--;
	}
	return (num);
}
