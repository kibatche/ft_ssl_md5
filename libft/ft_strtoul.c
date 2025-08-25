/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:44:15 by chbadad           #+#    #+#             */
/*   Updated: 2022/01/28 15:35:04 by chbadad          ###   ########.fr       */
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

unsigned long long	ft_strtoul(const char *nptr, char **endptr)
{
	unsigned long long	res;

	res = 0;
	while (ft_isspace_int((int)*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	if (!(ft_isdigit(*nptr)) || ft_strlen(nptr) > 20)
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
	return (res);
}
