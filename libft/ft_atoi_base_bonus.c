/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:59:35 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/29 12:22:42 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_from_base(char c)
{
	char	*base1;
	char	*base2;
	int		i;

	i = 0;
	base1 = "0123456789abcdefghijklmnopqrstuvwxyz";
	base2 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (base1[i] && base2[i])
	{
		if (c == base2[i] || c == base1[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int base)
{
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str && int_from_base(*str) != -1)
	{
		res = res * base + int_from_base(*str);
		str++;
	}
	return (res * sign);
}
