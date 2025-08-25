/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:44:15 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/25 14:12:35 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace_int(int c)
{
	const char	*spaces;

	spaces = " \t\n\r\v\f";
	while (*spaces)
	{
		if ((unsigned char)c == *spaces)
			return (1);
		spaces++;
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;
	int	count;

	res = 0;
	sign = 1;
	count = 0;
	while (ft_isspace_int((int)*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (++count && *nptr >= '0' && *nptr <= '9' && *nptr)
	{
		if (count > 19 && sign == -1)
			return (0);
		else if (count > 19 && sign == 1)
			return (-1);
		res = res * 10 + *nptr - 48;
		nptr++;
	}
	return (res * sign);
}
