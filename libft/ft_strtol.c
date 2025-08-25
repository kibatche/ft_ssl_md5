/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:44:15 by chbadad           #+#    #+#             */
/*   Updated: 2022/01/28 15:12:50 by chbadad          ###   ########.fr       */
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

long long	ft_strtol(const char *nptr, char **endptr)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while (ft_isspace_int((int)*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	if (!(ft_isdigit(*nptr)) || ft_strlen(nptr) > 19)
	{
		*endptr = (char *)nptr;
		return (0);
	}
	while (*nptr >= '0' && *nptr <= '9' && *nptr)
	{
		res = res * 10 + *nptr - 48;
		nptr++;
	}
	*endptr = (char *)nptr;
	return (res * sign);
}
