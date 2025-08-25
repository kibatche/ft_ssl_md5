/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:21:48 by chbadad           #+#    #+#             */
/*   Updated: 2022/01/13 15:24:20 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int nb, int base)
{
	int		count;
	long	n;

	n = (long)nb;
	count = 2;
	if (n < 0)
	{
		n *= -1;
		count += 1;
	}
	while (n >= base)
	{
		n /= base;
		count++;
	}
	return (count);
}

static char	*ft_itoazero(void)
{
	char	*convert;
	int		i;

	i = 0;
	convert = malloc(sizeof(char) * 2);
	if (!convert)
		return (NULL);
	convert[i] = '0';
	i++;
	convert[i] = 0;
	return (convert);
}

static void	ft_end_of_charray(char *str, int i, int sign)
{
	int	size;

	if (sign == -1)
		str[i++] = '-';
	str[i] = 0;
	size = ft_strlen(str);
	i = -1;
	while (++i < --size)
	{
		str[i] ^= str[size];
		str[size] ^= str[i];
		str[i] ^= str[size];
	}
}

static int	ft_abs_int(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*s_n;

	if (n == 0)
		return (ft_itoazero());
	sign = 1;
	i = 0;
	s_n = malloc(sizeof(char) * ft_count(n, 10));
	if (!s_n)
		return (NULL);
	if (n < 0)
		sign *= -1;
	while (ft_abs_int(n))
	{
		if (ft_abs_int(n) % 10 < 10)
			s_n[i++] = ft_abs_int(n % 10) + '0';
		else
			s_n[i++] = ft_abs_int(n % 10) + 'A' - 10;
		n = ft_abs_int(n / 10);
	}
	ft_end_of_charray(s_n, i, sign);
	return (s_n);
}
